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
    int n;
    cin >> n;
    vector<ll> a(n), sum(n + 1, 0), sum2(n + 2, 0);

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum[i + 1] = a[i] + sum[i];
    }

    ll tmp = 0, t = 0;

    for (int i = 1; i < n + 1; i++)
    {
        sum2[i + 1] = sum[i] + sum2[i];

        if (tmp <= sum2[i])
        {
            tmp = sum2[i];
            t = i - 1;
        }
    }

    ll d = 0;

    for (int i = 0; i <= t; i++)
    {
        d += a[i];
        ans = max(ans, tmp + d);
    }

    cout << ans << endl;
}
