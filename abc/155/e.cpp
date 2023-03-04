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

int main(void)
{
    string n;
    static int dp[1000010][2];

    cin >> n;

    dp[0][1] = 1;

    for (int i = 0; i < n.size(); i++)
    {
        int d = n[i] - '0';

        dp[i + 1][0] = min(dp[i][0] + d, dp[i][1] + 10 - d);
        dp[i + 1][1] = min(dp[i][0] + d + 1, dp[i][1] + 10 - d - 1);
    }

    cout << dp[n.size()][0] << endl;
}