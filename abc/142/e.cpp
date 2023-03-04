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
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    ll n, m;
    cin >> n >> m;

    vector<ll> a(m), key(m, 0);

    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        ll b;
        cin >> b;

        for (int j = 0; j < b; j++)
        {
            ll c;
            cin >> c;
            c--;

            key[i] |= 1 << c;
        }
    }

    vector<ll> dp(1 << n, INF);

    dp[0] = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 1 << n; j++)
        {
            dp[j | key[i]] = min(dp[j | key[i]], dp[j] + a[i]);
        }
    }

    cout << (dp[(1 << n) - 1] == INF ? -1 : dp[(1 << n) - 1]) << endl;
}
