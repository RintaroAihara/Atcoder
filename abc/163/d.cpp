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
    ll n, k;

    cin >> n >> k;

    vector<ll> sum(n + 2, 0);

    ll ans = 0;

    for (int i = 1; i <= n; i++)
    {
        sum[i + 1] = i + sum[i];
    }

    for (int i = k; i <= n + 1; i++)
    {
        ans += (sum[n + 1] - sum[n + 1 - i]) - (sum[i] - sum[0]) + 1;

        ans %= MOD;
    }

    cout << ans << endl;
}
