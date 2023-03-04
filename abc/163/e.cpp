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
    ll n;
    ll ans = 0;

    cin >> n;

    map<ll, ll, greater<ll>> a;

    set<ll> num;

    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;

        a.insert(P(x, i + 1));
    }

    for (int i = 1; i <= n; i++)
    {
        num.insert(i);
    }

    for (auto x : a)
    {
        if (abs(x.second - *num.begin()) > abs(x.second - *num.rbegin()))
        {
            ans += x.first * abs(x.second - *num.begin());
            num.erase(*num.begin());
        }
        else
        {
            ans += x.first * abs(x.second - *num.rbegin());
            num.erase(*num.rbegin());
        }
    }

    cout << ans << endl;
}
