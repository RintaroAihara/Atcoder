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
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    ll n, x, m;
    cin >> n >> x >> m;
    vector<ll> a(1000000, 0);
    map<ll, ll> p;
    a[0] = x;

    for (int i = 0; i < m; i++)
    {
        p[i] = INF;
    }

    ll end, start;

    for (int i = 0; i < 1000000; i++)
    {
        a[i + 1] = a[i] * a[i] % m;

        if (p[a[i]] != INF)
        {
            end = i;
            start = p[a[i]];
            break;
        }

        p[a[i]] = i;
    }

    ll ans = 0;

    for (int i = 0; i < start; i++)
    {
        ans += a[i];
    }

    ll tmp = 0;

    n -= start;

    for (int i = start, cnt = 0; i < end; i++, cnt++)
    {
        if (cnt < n % (end - start))
        {
            ans += a[i];
        }

        tmp += a[i];
    }

    ans += tmp * (n / (end - start));

    cout << ans << endl;
}
