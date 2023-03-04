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
    int N;
    vector<double> p;
    static double dp[3010][3010];
    int i, j;
    double ans = 0;

    cin >> N;

    p.resize(N + 1);

    dp[0][0] = 1;

    rep(i, 1, N)
    {
        cin >> p[i];
        rep(j, 0, i)
        {
            dp[i][j] = dp[i - 1][j] * (1 - p[i]) + dp[i - 1][j - 1] * p[i];
        }
    }

    rep(i, N / 2 + 1, N)
    {
        ans += dp[N][i];
    }

    printf("%.10f\n", ans);
}