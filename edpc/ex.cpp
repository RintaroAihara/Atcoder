#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
const long long INF = 1LL << 60;

int main()
{
    long long N, W;
    cin >> N >> W;
    long long w[110], v[110];

    for (int i = 0; i < N; i++)
        cin >> w[i] >> v[i];

    long long dp[110][101000] = {0};
    for (int i = 0; i < N; i++)
    {
        for (int w_sum = 0; w_sum <= W; w_sum++)
        {
            if (w_sum - w[i] >= 0)
            {
                chmax(dp[i + 1][w_sum], dp[i][w_sum - w[i]] + v[i]);
            }
            chmax(dp[i + 1][w_sum], dp[i][w_sum]);
        }
    }
    cout << dp[N][W] << endl;
}
