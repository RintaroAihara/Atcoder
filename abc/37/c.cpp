#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <queue>
#include <stack>
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main(void)
{
    int n, k;
    vector<ll> a, b;
    multiset<ll> s;
    int i, j;
    int x;
    ll lb, ub;
    int count = 1;

    cin >> n >> k;

    rep(i, 0, n)
    {
        cin >> x;
        a.push_back(x);
    }

    rep(i, 0, n)
    {
        cin >> x;
        b.push_back(x);
    }

    sort(b.begin(), b.end());

    lb = 0;
    ub = INF;

    while (ub - lb > 1)
    {
        ll mid = (lb + ub) / 2;
        ll ans = 0;
        
        rep(i, 0, n)
        {
            ans += upper_bound(b.begin(), b.end(), mid / a[i]) - b.begin();
        }

        if (ans >= k)
        {
            ub = mid;
        }
        else
        {
            lb = mid;
        }
    }

    cout << ub << endl;
}