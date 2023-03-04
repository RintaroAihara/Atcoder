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
    ll t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        ll l, r;
        cin >> l >> r;

        if (r - 2 * l < 0)
        {
            cout << 0 << endl;
            continue;
        }

        ll x = r - 2 * l;
        x += 2;

        ll ans = x * (x - 1) / 2;
        cout << ans << endl;
    }
}