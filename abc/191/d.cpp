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
    long double x, y, r;
    cin >> x >> y >> r;

    ll lx = round(x * 10000), ly =round(y * 10000), lr = round(r * 10000);
    ll ans = 0;

    for (ll i = ceil(y - r); i <= floor(y + r); i++)
    {
        ll left = -1, right = 1000000010;
        ll li = i * 10000 - ly;

        while (right - left > 1)
        {
            ll mid = (right + left) / 2;

            if (lr * lr >= mid * mid + li * li)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }

        ans += floor((long double)(lx + left) / (long double)10000) - ceil((long double)(lx - left) / (long double)10000) + 1;
    }

    cout << ans << endl;
}
