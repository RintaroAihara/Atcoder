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

int p;

ll power(ll x, ll y)
{
    ll ans = 1;
    while (y)
    {
        if (y & 1)
            ans = (ans * x) % p;
        x = (x * x) % p;
        y >>= 1;
    }
    return ans;
}

int main(void)
{
    int n;
    string s;
    int dp;
    ll ans = 0;
    map<ll, ll> count;

    cin >> n >> p >> s;

    vector<int> m(n + 1, 0), sum(n + 1, 0);

    if (10 % p == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if ((s[i] - '0') % p == 0)
            {
                ans += i + 1;
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            m[i] = ((s[i] - '0') % p) * power(10, n - i - 1);
            m[i] %= p;
        }

        count[0]++;

        for (int i = n; i > 0; i--)
        {
            sum[i - 1] = sum[i] + m[i - 1];
            sum[i - 1] %= p;
            count[sum[i - 1]]++;
        }

        for (auto x : count)
        {
            ans += x.second * (x.second - 1) / 2;
        }
    }

    cout << ans << endl;
}