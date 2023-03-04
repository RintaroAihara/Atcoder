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
#include <cassert>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

int main(void)
{
    ll h, w;
    cin >> h >> w;

    vector<string> a(h);

    for (int i = 0; i < h; i++)
    {
        cin >> a[i];
    }

    vector<vector<ll>> dp(h + 5, vector<ll>(w + 5, 0));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }

            if (i - 1 < 0)
            {
                dp[i][j] = dp[i][j - 1];
                continue;
            }

            if (j - 1 < 0)
            {
                dp[i][j] = dp[i - 1][j];
                continue;
            }

            if ((i + j) % 2 == 1)
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    if (a[i][j] == '+')
                    {
                        dp[i][j] = dp[i - 1][j] + 1;
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j] - 1;
                    }
                }
                else
                {
                    if (a[i][j] == '+')
                    {
                        dp[i][j] = dp[i][j - 1] + 1;
                    }
                    else
                    {
                        dp[i][j] = dp[i][j - 1] - 1;
                    }
                }
            }
            else
            {
                if (-dp[i - 1][j] > -dp[i][j - 1])
                {
                    if (a[i][j] == '+')
                    {
                        dp[i][j] = dp[i - 1][j] - 1;
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j] + 1;
                    }
                }
                else
                {
                    if (a[i][j] == '+')
                    {
                        dp[i][j] = dp[i][j - 1] - 1;
                    }
                    else
                    {
                        dp[i][j] = dp[i][j - 1] + 1;
                    }
                }
            }
        }
    }

    if (dp[h - 1][w - 1] == 0)
    {
        cout << "Draw" << endl;
    }
    else if (dp[h - 1][w - 1] > 0)
    {
        cout << "Takahashi" << endl;
    }
    else
    {
        cout << "Aoki" << endl;
    }
}