#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i, s, g) for (i = s; i <= g; i++)
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main()
{
    int H, W;
    char map[1000][1000];
    ll dp[1000][1000];
    bool flag = true;

    int i, j;
    cin >> H >> W;

    rep(i, 0, H - 1)
    {
        rep(j, 0, W - 1)
        {
            cin >> map[i][j];
        }
    }

    rep(i, 0, H - 1)
    {
        if (map[i][0] == '#')
        {
            flag = false;
        }

        if (flag)
        {
            dp[i][0] = 1;
        }
        else
        {
            dp[i][0] = 0;
        }
    }

    flag = true;

    rep(i, 0, W - 1)
    {
        if (map[0][i] == '#')
        {
            flag = false;
        }

        if (flag)
        {
            dp[0][i] = 1;
        }
        else
        {
            dp[0][i] = 0;
        }
    }

    dp[H - 1][j - 1] = 0;

    rep(i, 1, H - 1)
    {
        rep(j, 1, W - 1)
        {
            if (map[i][j] == '.')
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    cout << dp[H - 1][j - 1] << endl;
}