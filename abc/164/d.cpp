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
const ll MOD = 2019;
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
    string s;
    cin >> s;

    vector<ll> m(s.size() + 1);
    map<ll, ll> sum;
    ll ans = 0;
    m[s.size()] = 0;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        m[i] = m[i + 1] + (s[i] - '0') * power(10, s.size() - i - 1);
        m[i] %= 2019;
    }

    for (int i = 0; i <= s.size(); i++)
    {
        sum[m[i]]++;
    }

    for (auto x : sum)
    {
        ans += x.second * (x.second - 1) / 2;
    }

    cout << ans << endl;
}
