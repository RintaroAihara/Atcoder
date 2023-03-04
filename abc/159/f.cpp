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
const ll MOD = 998244353;
const ll INF = (1ll << 60);

int main(void)
{
    int n, s;
    ll ans = 0;

    cin >> n >> s;

    vector<int> a(n), sum(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sum[0] = 0;

    for (int i = 0; i < n; i++)
    {
        sum[i + 1] = sum[i] + a[i];
    }

    int x = 0, y = 1;

    while (y <= n)
    {
        if (x == y)
        {
            y++;
        }

        if (s > sum[y] - sum[x])
        {
            y++;
        }
        else if (s < sum[y] - sum[x])
        {
            x++;
        }
        else
        {
            ans += ((x + 1) * (n - y+1)) % MOD;
            ans %= MOD;
            y++;
        }
    }

    cout << ans << endl;
}