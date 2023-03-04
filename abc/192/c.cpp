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
#include <cassert>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

ll g1(ll x)
{
    ll ans = 0;
    vector<ll> a;

    while (x)
    {
        a.push_back(x % 10);
        x /= 10;
    }

    sort(a.begin(), a.end());

    ll ten = 1;

    for (int i = 0; i < a.size(); i++)
    {
        ans += a[i] * ten;
        ten *= 10;
    }

    return ans;
}

ll g2(ll x)
{
    ll ans = 0;
    vector<ll> a;

    while (x)
    {
        a.push_back(x % 10);
        x /= 10;
    }

    sort(a.begin(), a.end());

    ll ten = 1;

    for (int i = a.size() - 1; i >= 0; i--)
    {
        ans += a[i] * ten;
        ten *= 10;
    }

    return ans;
}

ll f(ll x)
{
    return g1(x) - g2(x);
}

int main(void)
{
    ll n, k;
    cin >> n >> k;

    vector<ll> a(k + 1);
    a[0] = n;

    for (int i = 0; i < k; i++)
    {
        a[i + 1] = f(a[i]);
    }

    cout << a[k] << endl;
    
}