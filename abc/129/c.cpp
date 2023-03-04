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
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    int n, m;

    cin >> n >> m;

    queue<int> a;
    vector<ll> dp(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        a.push(x);
    }

    dp[0] = 1;
    dp[1] = 1;

    if (a.front() == 1)
    {
        dp[1] = 0;
        a.pop();
    }

    for (int i = 2; i <= n; i++)
    {
        if (i == a.front() && a.size())
        {
            dp[i] = 0;
            a.pop();
            continue;
        }

        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        dp[i] %= MOD;
    }

    cout << dp[n] << endl;
}