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
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n), b(m), suma(n + 1, 0), sumb(m + 1, 0);

    for (auto &&i : a)
    {
        cin >> i;
    }

    for (int i = 0; i < n; i++)
    {
        suma[i + 1] = suma[i] + a[i];
    }

    for (auto &&i : b)
    {
        cin >> i;
    }

    for (int i = 0; i < m; i++)
    {
        sumb[i + 1] = sumb[i] + b[i];
    }

    ll ans = 0;

    for (int i = 0; i <= n; i++)
    {
        if (k - suma[i] < 0)
        {
            continue;
        }

        auto it = upper_bound(sumb.begin(), sumb.end(), k - suma[i]);

        ans = max(ans, ll(it - sumb.begin() + i - 1));
    }

    cout << ans << endl;
}
