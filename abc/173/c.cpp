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
    int h, w, k;
    cin >> h >> w >> k;

    vector<vector<char>> v(h, vector<char>(w, 0));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> v[i][j];
        }
    }

    ll ans = 0;

    for (int i = 0; i < (1 << h); i++)
    {
        for (int j = 0; j < (1 << w); j++)
        {
            int black = 0;
            for (int l = 0; l < h; l++)
            {
                for (int m = 0; m < w; m++)
                {
                    if (i & (1 << l) && j & (1 << m))
                    {
                        if (v[l][m] == '#')
                        {
                            black++;
                        }
                    }
                }
            }

            if (black == k)
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
}
