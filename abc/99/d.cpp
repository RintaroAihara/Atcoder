#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <tuple>
#include <numeric>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    int n, c;
    cin >> n >> c;

    vector<vector<int>> d(c, vector<int>(c));
    vector<vector<int>> g(n, vector<int>(n));

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> d[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
            g[i][j]--;
        }
    }

    vector<vector<int>> change_color(3, vector<int>(c + 1, 0));

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if ((j + k) % 3 == 0)
                {
                    change_color[0][i] += d[g[j][k]][i];
                }
                else if ((j + k) % 3 == 1)
                {
                    change_color[1][i] += d[g[j][k]][i];
                }
                else if ((j + k) % 3 == 2)
                {
                    change_color[2][i] += d[g[j][k]][i];
                }
            }
        }
    }

    ll ans = INF;

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c; j++)
        {
            for (int k = 0; k < c; k++)
            {
                if (i == j || j == k || k == i)
                {
                    continue;
                }

                ll tmp = change_color[0][i] + change_color[1][j] + change_color[2][k];
                ans = min(ans, tmp);
            }
        }
    }

    cout << ans << endl;
}
