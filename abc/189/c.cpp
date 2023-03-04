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
    cin >> n;

    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    a.push_back(0);

    ll ans = 0;

    stack<P> s;

    s.push({a[0], 0});

    for (int i = 1; i <= n; i++)
    {
        ll x = i;
        while (s.size() && a[i] < s.top().first)
        {
            P p = s.top();
            s.pop();
            ll tmp = p.first * (i - p.second);
            x = p.second;

            ans = max(ans, tmp);
        }

        s.push({a[i], x});
    }

    cout << ans << endl;
}
