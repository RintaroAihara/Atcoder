#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#define rep(i, s, g) for (i = s; i <= g; i++)
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll dp[3010][3010];

int main(void)
{
    int N;
    vector<int> a(3010);
    int i, j;
    int len;
    ll X = 0, Y = 0;

    cin >> N;

    a.resize(N);

    rep(i, 0, N - 1)
    {
        cin >> a[i];
    }

    memset(dp, 0, sizeof(dp));

    rep(len, 1, N)
    {
        rep(i, 0, N - len)
        {
            j = i + len;
            if ((N - len) % 2 == 0)
            {
                dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]);
            }
            else
            {
                dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
            }
        }
    }

    cout << dp[0][N] << endl;
}
