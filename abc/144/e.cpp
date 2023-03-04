#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <algorithm>
#include <vector>
#include <forward_list>
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

int main(void)
{
    ll n, k;
    vector<ll> a, f;
    int i;
    ll asum = 0;
    ll x;
    ll ok, ng;

    cin >> n >> k;

    a.resize(n);
    f.resize(n);

    rep(i, 0, n)
    {
        cin >> a[i];
    }
    
    rep(i, 0, n)
    {
        cin >> f[i];
    }

    sort(a.rbegin(), a.rend());
    sort(f.begin(), f.end());

    ok = INF, ng = -1;

    while (ok - ng > 1)
    {
        ll mid = (ok + ng) / 2;
        x = 0;

        rep(i, 0, n)
        {
            if (mid < a[i] * f[i])
            {
                x += max(0ll, a[i] - mid / f[i]);
            }
        }

        if (x <= k)
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }

    cout << ok << endl;
}