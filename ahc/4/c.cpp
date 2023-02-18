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

vector<pair<int, pair<string, vector<ll>>>> s;
vector<vector<char>> gene;
vector<bool> used;
vector<vector<ll>> alpha_tate;
vector<vector<ll>> alpha_yoko;

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

vector<vector<char>> split(int xa, int xb, int ya, int yb)
{

    for (int i = 0; i < m; i++)
    {
        bool d, best_flag = false; // trueが横,falseが縦
        int X, Y;
        int I;
        ll best_score = -1;

        for (int j = 0; j < m; j++)
        {
            if (used[j])
            {
                continue;
            }

            auto p = s[j];

            if (best_score > p.first)
            {
                break;
            }

            for (int x = xa; x < xb; x++)
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

                for (int y = ya; y < yb; y++)
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
                            d = true;
                            best_flag = true;
                            X = x, Y = y;
                            I = j;
                        }
                    }
                }
            }

            for (int y = ya; y < yb; y++)
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

                for (int x = xa; x < xb; x++)
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
                            I = j;
                        }
                    }
                }
            }
        }

        if (!best_flag)
        {
            break;
        }

        if (used[I])
        {
            continue;
        }

        if (d)
        {
            for (int i = 0; i < s[I].first; i++)
            {
                if (gene[X][(Y + i) % n] != s[I].second.first[i])
                {
                    alpha_yoko[X][s[I].second.first[i] - 'A']++;
                    alpha_tate[(Y + i) % n][s[I].second.first[i] - 'A']++;
                }

                gene[X][(Y + i) % n] = s[I].second.first[i];
            }
        }
        else
        {
            for (int i = 0; i < s[I].first; i++)
            {
                if (gene[(X + i) % n][Y] != s[I].second.first[i])
                {
                    alpha_yoko[(X + i) % n][s[I].second.first[i] - 'A']++;
                    alpha_tate[Y][s[I].second.first[i] - 'A']++;
                }

                gene[(X + i) % n][Y] = s[I].second.first[i];
            }
        }

        // cout << endl;
        // visualizer(gene);
        // this_thread::sleep_for(std::chrono::milliseconds(700));

        used[I] = true;
    }

    // for (int i = 0; i < m; i++)
    // {
    //     if (!used[i])
    //     {
    //         cout << s[i].second.first << endl;
    //     }
    // }

    return gene;
}

void Split(int h, int w)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            split(n / h * (i), n / h * (i + 1) - 1, n / w * (j), n / w * (j + 1) - 1);
        }
    }
}

int main(void)
{
    cin >> n >> m;

    s.assign(m, pair<int, pair<string, vector<ll>>>(0, pair<string, vector<ll>>(".", vector<ll>(10, 0))));

    for (int i = 0; i < m; i++)
    {
        cin >> s[i].second.first;
        s[i].first = s[i].second.first.size();

        for (int j = 0; j < s[i].first; j++)
        {
            s[i].second.second[s[i].second.first[j] - 'A']++;
        }
    }

    sort(s.begin(), s.end(), greater<pair<int, pair<string, vector<ll>>>>());
    gene.assign(n, vector<char>(n, '.'));
    used.assign(m, false);
    alpha_tate.assign(n, vector<ll>(8, 0)), alpha_yoko.assign(n, vector<ll>(8, 0));

    Split(2, 2);

    visualizer(gene);
}