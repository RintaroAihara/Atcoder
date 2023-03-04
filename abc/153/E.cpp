#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main(void)
{
    int H, N;
    int A, B;
    int i, j;
    int answer = MOD;

    vector<int> dp(20000, MOD);
    dp[0] = 0;

    cin >> H >> N;

    for (i = 1; i <= N; i++)
    {
        cin >> A >> B;
        for (j = 1; j <= H; j++)
        {
            dp[j] = min(dp[j], dp[max(0, j - A)] + B);
        }
    }

    cout << dp[H] << endl;
}