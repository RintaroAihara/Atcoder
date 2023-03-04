#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 40);

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

int main(void)
{
    ll n, m;
    cin >> n >> m;
    vector<double> x(n), y(n), p(m), q(m);

    for (int i = 0; i < n + m; i++)
    {
        cin >> x[i] >> y[i];
    }

    vector<vector<double>> d(n + m, vector<double>(n + m, 0));

    for (int i = 0; i < n + m; i++)
    {
        for (int j = 0; j < n + m; j++)
        {
            d[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            d[j][i] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
        }
    }

    double ans = INF;

    for (int i = 0; i < 1 << m; i++)
    {
        vector<vector<vector<double>>> dp((1ll << (n + m)), vector<vector<double>>(n + m, vector<double>(m + 1, INF)));

        dp[(1 << (n + m)) - 1][0][0] = 0;

        for (int s = (1 << (n + m)) - 2; s >= 0; s--)
        {
            for (int v = 0; v < n + m; v++)
            {
                if (v - n >= 0)
                {
                    if (i >> (v - n) & 1)
                    {
                    }
                    else
                    {
                        continue;
                    }
                }

                for (int u = 0; u < n + m; u++)
                {
                    if (u - n >= 0)
                    {
                        if (i >> (u - n) & 1)
                        {
                        }
                        else
                        {
                            continue;
                        }
                    }
                    for (int j = 0; j <= m; j++)
                    {
                        if (!(s >> u & 1))
                        {
                            if (u >= n)
                            {
                                if (j != 0)
                                {
                                    double t;
                                    if (j == 1)
                                    {
                                        t = d[u][v];
                                    }
                                    else
                                    {
                                        t = d[u][v] / (j - 1);
                                    }

                                    dp[s][v][j] = min(dp[s][v][j], dp[s | 1 << u][u][j - 1] + t);
                                }
                            }
                            else
                            {
                                double t;
                                if (j == 0)
                                {
                                    t = d[u][v];
                                }
                                else
                                {
                                    t = d[u][v] / j;
                                }
                                dp[s][v][j] = min(dp[s][v][j], dp[s | 1 << u][u][j] + t);
                            }
                        }
                    }
                }
            }
        }

        for (int z = 0; z <= m; z++)
        {
            cout << dp[0][0][z] << endl;
        }
    }
}