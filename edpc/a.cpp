#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main(void)
{
    int N;
    int i;
    vector<int> h(100100);
    vector<int> dp(100100, MOD);

    cin >> N;
    for (i = 1; i <= N; i++)
    {
        cin >> h[i];
    }

    dp[0] = dp[1] = 0;

    for (i = 2; i <= N; i++)
    {
        dp[i] = min(abs(h[i] - h[i - 1]) + dp[i - 1], abs(h[i] - h[max(i - 2, 1)]) + dp[max(i - 2, 1)]);
    }

    cout << dp[N] << endl;
}