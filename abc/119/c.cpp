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
    ll ans1 = INF;

    cin >> n >> a >> b >> c;

    vector<ll> l(n);

    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }

    ll al, bl, cl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i)
            {
                continue;
            }

            for (int k = 0; k < n; k++)
            {
                if (j == k || k == i)
                {
                    continue;
                }
                
                for (int x = 0; x < 32; x++)
                {
                    for (int y = 0; y < 32; y++)
                    {
                        al = l[i], bl = l[j], cl = l[k];
                        ll res = 0;

                        for (int z = 0, count = 0; z < n; z++)
                        {
                            if (z == i || z == j || z == k)
                            {
                                continue;
                            }

                            res += 10;

                            if (x & (1 << count))
                            {
                                if (y & (1 << count))
                                {
                                    al += l[z];
                                }
                                else
                                {
                                    bl += l[z];
                                }
                            }
                            else
                            {
                                if (y & (1 << count))
                                {
                                    cl += l[z];
                                }
                                else
                                {
                                    res -= 10;
                                }
                            }

                            count++;
                        }

                        ans = min(ans, res + abs(a - al) + abs(b - bl) + abs(c - cl));
                    }
                }
            }
        }
    }

    cout << ans << endl;
}
