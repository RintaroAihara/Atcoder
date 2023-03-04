#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i, s, g) for (i = s; i <= g; i++)
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

vector<vector<int>> G;
vector<int> dp(100010, -1);

int memorize(int n)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int res = 0;
    for (auto x : G[n])
    {
        res = max(res, memorize(x) + 1);
    }

    return dp[n] = res;
}

int main(void)
{
    int N, M;
    int x, y;
    int i, j;
    int ans = 0;

    cin >> N >> M;

    G.assign(N + 1, vector<int>());

    rep(i, 1, M)
    {
        cin >> x >> y;
        G[x].push_back(y);
    }

    rep(i, 1, N)
    {
        ans = max(ans, memorize(i));
    }

    cout << ans << endl;
}