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

ll power(ll x, ll y)
{
    ll ans = 1;
    while (y)
    {
        if (y & 1)
            ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return ans;
}

int main(void)
{
    string l;

    ll ans = 0;
    ll n = 0;

    cin >> l;

    for (int i = 0; i < l.size(); i++)
    {
        int d = l[i] - '0';
        ll len = l.size() - i - 1;

        if (d == 1)
        {
            ans += (power(2, n) * power(3, len)) % MOD;
            ans %= MOD;
            n++;
        }
    }

    ans += power(2, n);
    ans %= MOD;

    cout << ans << endl;
}