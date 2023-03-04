#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main(void)
{
    int N, K;
    int i, j;
    int n;
    int MIN;
    vector<int> h(100010);
    vector<int> dp(100010, MOD);

    cin >> N;
    cin >> K;
    for (i = 1; i <= N; i++)
    {
        cin >> h[i];
    }

    dp[0] = dp[1] = 0;

    for (i = 2; i <= N; i++)
    {
        for (j = 1, MIN = MOD; j <= K; j++)
        {
            n = max(i - j, 1);
            int tmp = abs(h[i] - h[n]) + dp[n];
            if (MIN > tmp)
            {
                MIN = tmp;
            }
        }
        dp[i] = MIN;
    }

    cout << dp[N] << endl;
}