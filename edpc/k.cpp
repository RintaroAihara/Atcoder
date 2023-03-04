#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#define rep(i, s, g) for (i = s; i <= g; i++)
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int N, K;

int main()
{
    int i, j, k;
    vector<bool> dp(100010, false);
    int a[105];
    int MIN = 9999999;
    int n;

    cin >> N >> K;

    rep(i, 0, N - 1)
    {
        cin >> a[i];
    }

    rep(i, 0, K)
    {
        rep(j, 0, N - 1)
        {
            if (i - a[j] >= 0)
            {
                if (dp[i - a[j]] == false)
                {
                    dp[i] = true;
                }
            }
        }
    }

    if (dp[K] == false)
    {
        cout << "Second" << endl;
    }
    else
    {
        cout << "First" << endl;
    }
}