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

vector<vector<char>> make_initial_solution(vector<pair<int, string>> s)
{
    vector<vector<char>> gene(n, vector<char>(n, '.'));

    for (int I = 0; I < m; I++)
    {
        auto p = s[I];

        bool tate, yoko, best_flag = false; // trueが横,falseが縦
        int x, y;
        ll best_score = INF;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ll score = 0;
                bool flag = true;

                for (int k = 0; k < p.first; k++)
                {
                    if (gene[i][(j + k) % n] != p.second[k] && gene[i][(j + k) % n] != '.')
                    {
                        flag = false;
                        break;
                    }

                    if (gene[i][(j + k) % n] != p.second[k])
                    {
                        score++;
                    }
                }

                if (flag)
                {
                    if (chmin(best_score, score))
                    {
                        yoko = true;
                        tate = false;
                        best_flag = true;
                        x = i, y = j;
                    }
                }

                flag = true;
                score = 0;

                for (int k = 0; k < p.first; k++)
                {
                    if (gene[(i + k) % n][j] != p.second[k] && gene[(i + k) % n][j] != '.')
                    {
                        flag = false;
                        break;
                    }

                    if (gene[(i + k) % n][j] != p.second[k])
                    {
                        score++;
                    }
                }

                if (flag)
                {
                    if (chmin(best_score, score))
                    {
                        yoko = false;
                        tate = true;
                        best_flag = true;
                        x = i, y = j;
                    }
                }
            }
        }

        if (!best_flag)
        {
            // cout << p.second << endl;
            continue;
        }

        for (int i = 0; i < p.first; i++)
        {
            gene[(x + (i * tate)) % n][(y + (i * yoko)) % n] = p.second[i];
        }
    }

    return gene;
}

int main(void)
{
    cin >> n >> m;

    vector<pair<int, string>> s(m);

    for (int i = 0; i < m; i++)
    {
        cin >> s[i].second;
        s[i].first = s[i].second.size();
    }

    sort(s.begin(), s.end(), greater<pair<int, string>>());

    auto initial_gene = make_initial_solution(s);

    visualizer(initial_gene);
}