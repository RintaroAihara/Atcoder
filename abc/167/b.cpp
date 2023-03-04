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
    ll a, b, c, k;
    ll ans = 0;

    cin >> a >> b >> c >> k;

    if (a >= k)
    {
        ans += k;
    }
    else if (a + b >= k)
    {
        ans += a;
    }
    else
    {
        ans += a - (k - a - b);
    }

    cout << ans << endl;
}
