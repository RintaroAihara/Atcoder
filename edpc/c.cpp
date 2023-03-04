#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define ran(i, s, g) for (i = s; i <= g; i++)
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main(void)
{
    int N;
    int i, j, k;
    int dp[3][100010] = {0};
    vector<int> a(100010), b(100010), c(100010);

    cin >> N;

    ran(i, 1, N)
    {
        cin >> a[i] >> b[i] >> c[i];
    }

    ran(i, 1, N)
    {
        dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + a[i];
        dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + b[i];
        dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + c[i];
    }

    int x = max({dp[0][N], dp[1][N], dp[2][N]});

    cout << x << endl;

    return 0;
}
