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
    vector<ll> a(n), s(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s[i + 1] = a[i] + s[i];
        s[i + 1] %= MOD;
    }

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += a[i] * ((s[n] - s[i + 1] + MOD) % MOD);
        ans %= MOD;
    }

    cout << ans << endl;
}
