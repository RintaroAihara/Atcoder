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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    ll l, r;
    ll ans = 2018;

    cin >> l >> r;

    if (r - l > 2019)
    {
        cout << 0 << endl;
        return 0;
    }

    for (ll i = l; i < r; i++)
    {
        for (ll j = i + 1; j <= r; j++)
        {
            ans = min(ans, (i * j % 2019));
        }
    }

    cout << ans << endl;
}