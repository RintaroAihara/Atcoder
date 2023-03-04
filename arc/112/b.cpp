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
#include <cassert>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    ll b, c;
    cin >> b >> c;

    ll ans;

    ll pu, pl;
    ll nu, nl;

    if (b > 0)
    {
        pu = max(-(-b - (c - 2) / 2), b);
        pl = max(0ll, b - c / 2);
        nu = min(0ll, -(b - (c - 1) / 2));
        nl = -b - (c - 1) / 2;
    }
    else
    {
        pu = -(b - (c - 1) / 2);
        pl = max(0ll, -b - (c - 1) / 2);
        // cout << pu << endl;
        // cout << pl << endl;
        nu = min(0ll, -(-b - (c - 2) / 2));
        nl = b - c / 2;
    }

    ans = pu - pl + 1 + nu - nl + 1;

    if (pl == 0 && nu == 0)
    {
        ans--;
    }

    cout << ans << endl;
}