#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#define rep(i, s, g) for (i = s; i <= g; i++)
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main(void)
{
    int N;
    int i, j;
    int B;
    int ans = 0;
    int dp[10][10];

    cin >> N;

    memset(dp, 0, sizeof(dp));

    rep(i, 1, N)
    {
        int tmp = i;
        while (tmp >= 10)
        {
            tmp /= 10;
        }

        dp[tmp % 10][i % 10]++;
    }

    rep(i, 0, 9)
    {
        rep(j, 0, 9)
        {
            ans += dp[j][i] * dp[i][j];
        }
    }

    cout << ans << endl;
}