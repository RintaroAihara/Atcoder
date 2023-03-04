#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 62) - 1;

int main(void)
{
    int n, m, l;
    int a, b, c;
    int q;
    vector<int> s(100010), t(100010);
    ll d[500][500], count[500][500];
    int i, j, k;

    cin >> n >> m >> l;

    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            if (i == j)
            {
                d[i][j] = 0;
            }
            else
            {
                d[i][j] = INF;
            }
        }
    }

    rep(i, 0, m)
    {
        cin >> a >> b >> c;

        d[a - 1][b - 1] = c;
        d[b - 1][a - 1] = c;
    }

    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            rep(k, 0, n)
            {
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);

                if (j == k)
                {
                    count[j][k] = 0;
                }
                else if (d[j][k] <= l)
                {
                    count[j][k] = 1;
                }
                else
                {
                    count[j][k] = INF;
                }
            }
        }
    }

    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            rep(k, 0, n)
            {
                count[j][k] = min(count[j][k], count[j][i] + count[i][k]);
            }
        }
    }

    cin >> q;

    rep(i, 0, q)
    {
        cin >> s[i] >> t[i];
    }

    rep(i, 0, q)
    {
        if (count[s[i] - 1][t[i] - 1] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << count[s[i] - 1][t[i] - 1] - 1 << endl;
        }
    }
}