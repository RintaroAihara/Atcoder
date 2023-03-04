#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1e18) + 1;

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
    int n;
    ll a;
    int i, j;
    vector<int> digit(100, 0);
    ll ans = 0;

    cin >> n;

    rep(i, 0, n)
    {
        cin >> a;

        rep(j, 1, 70)
        {
            if (a & 1)
            {
                digit[j]++;
            }

            a >>= 1;

            if (a == 0)
            {
                break;
            }
        }
    }

    rep(i, 1, 70)
    {
        ans += (power(2, i - 1) * digit[i]) % MOD * (n - digit[i]);
        ans %= MOD;
    }

    cout << ans << endl;
}