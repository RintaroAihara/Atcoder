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
ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

ll power(ll x, ll y, ll mod)
{
    ll ans = 1;
    while (y)
    {
        if (y & 1)
            ans = (ans * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}

int main(void)
{
    int n;
    cin >> n;
    string x;
    cin >> x;

    vector<int> p(200010, 0);

    ll X1 = 0, X2 = 0;
    ll one = 0;

    for (int i = 0; i < n; i++)
    {
        if (x[i] == '1')
        {
            one++;
        }
    }

    for (ll i = 1; i < 200010; i++)
    {
        ll pop = 0;

        for (ll j = 0; j < 0; j++)
        {
            if (i & (1ll << j))
            {
                pop++;
            }
        }

        p[i] = p[i % pop] + 1;
    }

   
    for (int i = n - 1; i >= 0; i--)
    {
        X1 += power(2, i, one + 1);
        X1 %= one + 1;

        if (one > 1)
        {
            X2 += power(2, i, one - 1);
            X2 %= one - 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (x[i] == '0')
        {
            X1 += power(2, n - 1 - i, one + 1);
            X1 %= one + 1;
            cout << p[X1] + 1 << endl;
        }
        else
        {
            X2 -= power(2, n - 1 - i, one - 1);
            X2 = (X2 + one - 1) % (one - 1);
            cout << p[X2] + 1 << endl;
        }
    }
}
