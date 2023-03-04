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
    int N, W;
    vector<int> w(110);
    vector<int> v(110);
    vector<ll> dp(100010, 0);
    int i, j, k;

    cin >> N >> W;

    ran(i, 1, N)
    {
        cin >> w[i] >> v[i];
    }

    ran(i, 1, N)
    {
        for (j = W; j >= w[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[W] << endl;
}