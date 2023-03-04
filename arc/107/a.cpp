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
const ll MOD = 998244353;
const ll INF = (1ll << 60);

int main(void)
{
    ll a, b, c;
    cin >> a >> b >> c;

    ll ans = 0;
    ans += a * (a + 1) / 2;
    ans %= MOD;
    ans *= (b * (b + 1) / 2) % MOD;
    ans %= MOD;
    ans *= (c * (c + 1) / 2) % MOD;
    ans %= MOD;

    cout << ans << endl;
}
