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
    int h, w;
    cin >> h >> w;

    vector<string> s(h, string());

    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
    }

    ll ans = 0;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] == '.')
            {
                if (i + 1 < h)
                {
                    if (s[i + 1][j] == '.')
                    {
                        ans++;
                    }
                }

                if (j + 1 < w)
                {
                    if (s[i][j + 1] == '.')
                    {
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans << endl;
}
