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
    string l;

    static ll dp[100010][2];

    dp[0][0] = 1;

    cin >> l;

    for (int i = 0; i < l.size(); i++)
    {
        ll d = l[i] - '0';

        if (d == 1)
        {
            dp[i + 1][1] = ((dp[i][1] * 3) % MOD + dp[i][0]) % MOD;
            dp[i + 1][0] = (dp[i][0] * 2) % MOD;
        }
        else
        {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = (dp[i][1] * 3) % MOD;
        }

        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
    }

    cout << (dp[l.size()][0] + dp[l.size()][1]) % MOD << endl;
}