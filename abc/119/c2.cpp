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
    ll n, a, b, c;

    ll ans = INF;

    cin >> n >> a >> b >> c;

    vector<ll> l(n);

    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }

    ll len[3];
    vector<ll> p = {0, 1, 2};

    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < (1 << n); j++)
        {
            ll cost = 0;
            len[0] = 0, len[1] = 0, len[2] = 0;

            for (int k = 0; k < n; k++)
            {
                if (i & (1 << k))
                {
                    if (j & (1 << k))
                    {
                        len[0] += l[k];
                        cost += 10;
                    }
                    else
                    {
                        len[1] += l[k];
                        cost += 10;
                    }
                }
                else
                {
                    if (j & (1 << k))
                    {
                        len[2] += l[k];
                        cost += 10;
                    }
                }
            }

            if (len[0] == 0 || len[1] == 0 || len[2] == 0)
            {
                continue;
            }

            do
            {
                ans = min(ans, cost - 30 + abs(a - len[p[0]]) + abs(b - len[p[1]]) + abs(c - len[p[2]]));
            } while (next_permutation(p.begin(), p.end()));
        }
    }

    cout << ans << endl;
}
