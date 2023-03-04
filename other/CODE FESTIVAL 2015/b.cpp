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
    ll n;
    string s;
    cin >> n >> s;

    ll length = 0;

    for (int i = 1; i < n; i++)
    {
        string a, b;
        a = s.substr(0, i);
        b = s.substr(i);

        vector<vector<ll>> dp(i + 1, vector<ll>(n - i + 1, 0));

        for (int j = 0; j < a.size(); j++)
        {
            for (int k = 0; k < b.size(); k++)
            {
                if (a[j] == b[k])
                {
                    dp[j + 1][k + 1] = dp[j][k] + 1;
                }
                else
                {
                    dp[j + 1][k + 1] = max(dp[j][k + 1], dp[j + 1][k]);
                }
            }
        }

        length = max(length, dp[a.size()][b.size()]);
    }

    cout << n - length * 2 << endl;
}
