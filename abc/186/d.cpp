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
    ll n, m;

    cin >> n >> m;

    vector<int> a(m + 1), b;

    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    a[m] = n + 1;

    sort(a.begin(), a.end());

    ll x = INF;
    ll p = 0;

    for (int i = 0; i < m + 1; i++)
    {
        if (a[i] - p - 1)
        {
            x = min(x, a[i] - p - 1);
            b.push_back(a[i] - p - 1);
        }

        p = a[i];
    }

    ll ans = 0;

    for (auto &&i : b)
    {
        ans += (i + x - 1) / x;
    }

    cout << ans << endl;
}
