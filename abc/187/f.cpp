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
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> g(n, vector<bool>(n, false));

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a][b] = g[b][a] = true;
    }

    vector<ll> clique(1 << n, true);

    for (int bit = 0; bit < 1 << n; bit++)
    {
        vector<int> s;
        for (int i = 0; i < n; i++)
        {
            if (bit & (1 << i))
            {
                s.push_back(i);
            }
        }

        for (int i = 0; i < s.size() && clique[bit]; i++)
        {
            for (int j = i + 1; j < s.size() && clique[bit]; j++)
            {
                clique[bit] = g[s[i]][s[j]];
            }
        }
    }

    vector<ll> dp(1 << n, INF);

    dp[0] = 0;

    for (int bit = 0; bit < 1 << n; bit++)
    {
        if (dp[bit] >= INF)
        {
            continue;
        }

        int varbit = ((1 << n) - 1) ^ bit;

        for (int add = varbit; add; add = (add - 1) & varbit)
        {
            if (clique[add])
            {
                dp[bit | add] = min(dp[bit | add], dp[bit] + 1);
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;
}
