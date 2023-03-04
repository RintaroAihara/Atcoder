#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
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
const ll MOD = 1e9;
const ll INF = (1ll << 60);

ll power(ll x, ll y)
{
    ll ans = 1;

    while (y)
    {
        if (y & 1)
        {
            if (ans > 1000000000 / x)
            {
                return 1000000010;
            }
            ans = (ans * x);
        }

        x = (x * x);
        y >>= 1;
    }
    return ans;
}

int main(void)
{
    ll a, r, n;

    cin >> a >> r >> n;

    ll ans = a;

    ans *= power(r, n - 1);

    if (ans > 1000000000)
    {
        cout << "large" << endl;
    }
    else
    {
        cout << ans << endl;
    }
}
