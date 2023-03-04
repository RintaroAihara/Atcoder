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
    ll n;
    cin >> n;

    vector<ll> x(n), y(n), h(n);

    int ok;

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> h[i];
        if (h[i] > 0)
        {
            ok = i;
        }
    }

    ll cx, cy;

    for (cx = 0; cx <= 100; cx++)
    {
        for (cy = 0; cy <= 100; cy++)
        {
            ll H = h[ok] + abs(x[ok] - cx) + abs(y[ok] - cy);
            bool flag = true;

            for (int i = 0; i < n; i++)
            {
                if (H - abs(x[i] - cx) - abs(y[i] - cy) != h[i] && h[i] > 0)
                {
                    flag = false;
                }

                if (h[i] == 0 && H - abs(x[i] - cx) - abs(y[i] - cy) > 0)
                {
                    flag = false;
                }
            }

            if (flag)
            {
                printf("%lld %lld %lld\n", cx, cy, H);
                return 0;
            }
        }
    }
}
