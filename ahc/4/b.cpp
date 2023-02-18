#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

ll n, m;

// 表示
void visualizer(vector<vector<char>> gene)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << gene[i][j];
        }

        cout << endl;
    }
}

vector<vector<char>> optimize(vector<pair<int, pair<string, vector<ll>>>> str)
{
    vector<vector<char>> gene(n, vector<char>(n, '.'));                                  //全体の遺伝子
    vector<bool> used(m, false);                                                         //使用した文字列
    vector<vector<ll>> alpha_tate(n, vector<ll>(8, 0)), alpha_yoko(n, vector<ll>(8, 0)); //縦と横の文字の数
    vector<vector<vector<ll>>> gene_if(n, vector<vector<ll>>(n, vector<ll>(8, 0)));      //スコア計算用

    for (int i = 0; i < m; i++)
    {
        bool d;                 //最適値が更新されたかの判定
        bool best_flag = false; // trueが横,falseが縦
        int X, Y;
        int Index;
        ll best_score = -1;

        for (int j = 0; j < m; j++)
        {
            if (used[j])
            {
                continue;
            }

            auto p = str[j];

            if (best_score > p.first)
            {
                break;
            }

            for (int x = 0; x < n; x++)
            {
                ll able_score = 0;

                for (int k = 0; k < 8; k++)
                {
                    able_score += min(alpha_yoko[x][k], p.second.second[k]);
                }

                if (able_score <= best_score)
                {
                    break;
                }

                for (int y = 0; y < n; y++)
                {
                    ll score = 0;
                    bool flag = true;

                    for (int k = 0; k < p.first; k++)
                    {
                        if (gene[x][(y + k) % n] != p.second.first[k] && gene[x][(y + k) % n] != '.')
                        {
                            flag = false;
                            break;
                        }

                        if (gene[x][(y + k) % n] == p.second.first[k])
                        {
                            score++;
                            score += gene_if[x][(y + k) % n][p.second.first[k] - 'A'];
                        }
                    }

                    if (score == p.first)
                    {
                        used[j] = true;
                    }

                    if (flag)
                    {
                        // 最適値の更新
                        if (chmax(best_score, score))
                        {
                            d = true;
                            best_flag = true;
                            X = x, Y = y;
                            Index = j;
                        }
                    }
                }
            }

            for (int y = 0; y < n; y++)
            {
                ll able_score = 0;

                for (int k = 0; k < 8; k++)
                {
                    able_score += min(alpha_tate[y][k], p.second.second[k]);
                }

                if (able_score <= best_score)
                {
                    break;
                }

                for (int x = 0; x < n; x++)
                {
                    ll score = 0;
                    bool flag = true;

                    for (int k = 0; k < p.first; k++)
                    {
                        if (gene[(x + k) % n][y] != p.second.first[k] && gene[(x + k) % n][y] != '.')
                        {
                            flag = false;
                            break;
                        }

                        if (gene[(x + k) % n][y] == p.second.first[k])
                        {
                            score++;
                            score += gene_if[(x + k) % n][y][p.second.first[k] - 'A'];
                        }
                    }

                    if (score == p.first)
                    {
                        used[j] = true;
                    }

                    if (flag)
                    {
                        if (chmax(best_score, score))
                        {
                            d = false;
                            best_flag = true;
                            X = x, Y = y;
                            Index = j;
                        }
                    }
                }
            }
        }

        if (!best_flag)
        {
            break;
        }

        if (used[Index])
        {
            continue;
        }

        if (d)
        {
            for (int j = 0; j < str[Index].first; j++)
            {
                if (gene[X][(Y + j) % n] != str[Index].second.first[j])
                {
                    alpha_yoko[X][str[Index].second.first[j] - 'A']++;
                    alpha_tate[(Y + j) % n][str[Index].second.first[j] - 'A']++;
                }

                gene[X][(Y + j) % n] = str[Index].second.first[j];
            }
        }
        else
        {
            for (int j = 0; j < str[Index].first; j++)
            {
                if (gene[(X + j) % n][Y] != str[Index].second.first[j])
                {
                    alpha_yoko[(X + j) % n][str[Index].second.first[j] - 'A']++;
                    alpha_tate[Y][str[Index].second.first[j] - 'A']++;
                }

                gene[(X + j) % n][Y] = str[Index].second.first[j];
            }
        }

        bool end_flag = false; // 終了のフラグ

        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if (gene[x][y] != '.')
                {
                    continue;
                }

                for (int j = m - 1; j > 0; j--)
                {
                    if (used[j])
                    {
                        continue;
                    }

                    if (str[j].first > 5)
                    {
                        end_flag = true;
                        break;
                    }

                    for (int k = 0; k < 8; k++)
                    {

                        if (str[j].second.second[k] == 0)
                        {
                            continue;
                        }

                        ll z = 0;

                        for (int l = 0; l < str[j].first; l++)
                        {
                            int nx = x, ny = (y - l + n) % n;

                            for (int r = 0; r < str[j].first; r++)
                            {
                                if (gene[nx][ny] != str[j].second.first[r] && gene[nx][ny] != '.')
                                {
                                    z = 0;
                                    continue;
                                }

                                if (gene[nx][ny] == str[j].second.first[r])
                                {
                                    z++;
                                }
                            }
                        }

                        chmax(gene_if[x][y][k], z);
                    }
                }

                if (end_flag)
                {
                    break;
                }
            }

            if (end_flag)
            {
                break;
            }
        }

        used[Index] = true;
    }

    return gene;
}

int main(void)
{
    // 入力処理
    cin >> n >> m;

    vector<pair<int, pair<string, vector<ll>>>> str(m, pair<int, pair<string, vector<ll>>>(0, pair<string, vector<ll>>(".", vector<ll>(10, 0))));

    for (int i = 0; i < m; i++)
    {
        cin >> str[i].second.first;
        str[i].first = str[i].second.first.size();

        for (int j = 0; j < str[i].first; j++)
        {
            str[i].second.second[str[i].second.first[j] - 'A']++;
        }
    }

    sort(str.begin(), str.end(), greater<pair<int, pair<string, vector<ll>>>>());

    // 最適化
    auto best_gene = optimize(str);

    // 表示
    visualizer(best_gene);
}