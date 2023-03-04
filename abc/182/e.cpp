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
    ll h, w, n, m;
    cin >> h >> w >> n >> m;

    vector<vector<bool>> light(h, vector<bool>(w, false)), block;
    block = light;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;

        light[x][y] = true;
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;

        block[x][y] = true;
    }

    vector<vector<bool>> ok(h, vector(w, false));

    for (int i = 0; i < h; i++)
    {
        bool flag = false;
        for (int j = 0; j < w; j++)
        {
            if (light[i][j])
            {
                flag = true;
            }

            if (block[i][j])
            {
                flag = false;
            }

            if (flag)
            {
                ok[i][j] = flag;
            }
        }

        flag = false;
        for (int j = w - 1; j >= 0; j--)
        {
            if (light[i][j])
            {
                flag = true;
            }

            if (block[i][j])
            {
                flag = false;
            }

            if (flag)
            {
                ok[i][j] = flag;
            }
        }
    }

    for (int i = 0; i < w; i++)
    {
        bool flag = false;
        for (int j = 0; j < h; j++)
        {
            if (light[j][i])
            {
                flag = true;
            }

            if (block[j][i])
            {
                flag = false;
            }

            if (flag)
            {
                ok[j][i] = flag;
            }
        }

        flag = false;
        for (int j = h - 1; j >= 0; j--)
        {
            if (light[j][i])
            {
                flag = true;
            }

            if (block[j][i])
            {
                flag = false;
            }

            if (flag)
            {
                ok[j][i] = flag;
            }
        }
    }

    ll ans = 0;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (ok[i][j])
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
}
