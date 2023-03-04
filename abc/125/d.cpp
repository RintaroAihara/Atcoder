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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    int n;
    ll ans = 0;

    cin >> n;

    vector<ll> a(n);
    ll x = INF, xi = 0;
    ll res = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        res += abs(a[i]);

        x = min(x, abs(a[i]));
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < 0)
        {
            a[i] *= -1;
            a[i + 1] *= -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        ans += a[i];
    }

    cout << max(ans, res - x * 2) << endl;
}