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

    vector<ll> a(n + 3), pok(n + 3, 0), v(n + 3, 0);

    for (ll i = 0; i <= n; i++)
    {
        cin >> a[i];
    }

    pok[0] = 1 - a[0];

    for (ll i = 1; i <= n; i++)
    {
        pok[i] = min(pok[i - 1] * 2 - a[i], INF);
    }

    v[n] = a[n];

    ll ans = 0;

    for (ll i = n - 1; i >= 0; i--)
    {
        v[i] = min(v[i + 1], pok[i]) + a[i];
    }

    for (ll i = 0; i <= n; i++)
    {
        ans += v[i];

        if (pok[i] < 0)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;
}
