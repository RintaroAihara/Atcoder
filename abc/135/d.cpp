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

ll power(ll x, ll y)
{
    ll ans = 1;
    while (y)
    {
        if (y & 1)
            ans = (ans * x) % 13;
        x = (x * x) % 13;
        y >>= 1;
    }
    return ans;
}

int main(void)
{
    string s;

    static ll dp[100010][13];

    cin >> s;

    dp[0][0] = 1;

    for (int i = 0; i <= s.size(); i++)
    {
        int c;

        if (s[i] == '?')
        {
            c = -1;
        }
        else
        {
            c = s[i] - '0';
        }

        for (int j = 0; j < 10; j++)
        {
            if (c == -1 || c == j)
            {
                for (int k = 0; k < 13; k++)
                {
                    dp[i + 1][(k * 10 + j) % 13] += dp[i][k];
                }
            }
        }

        for (int j = 0; j < 13; j++)
        {
            dp[i + 1][j] %= MOD;
        }
    }

    cout << dp[s.size()][5] << endl;
}