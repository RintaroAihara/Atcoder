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
    ll n, k;
    ll ans = 0;

    cin >> n >> k;

    vector<ll> a(n + 1), sum(n + 1);

    sum[0] = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }

    for (int i = 0; i < n; i++)
    {
        ll ng = -1, ok = n + 1;
        ll mid;

        while (ok - ng > 1)
        {
            mid = (ok + ng) / 2;

            if (sum[mid] - sum[i] >= k)
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }

        if (n + 1 - ok > 0)
        {
            ans += n - ok + 1;
        }
    }

    cout << ans << endl;
}