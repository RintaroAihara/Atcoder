#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <tuple>
#include <numeric>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

vector<vector<vector<double>>> dp(120, vector<vector<double>>(120, vector<double>(120, -1)));

double dfs(int x, int y, int z)
{
    if (x == 100 || y == 100 || z == 100)
    {
        return 0;
    }

    if (dp[x][y][z] >= 0.0)
        return dp[x][y][z];

    double res = 0;

    res += (double)(x) / (x + y + z) * (dfs(x + 1, y, z) + 1);
    res += (double)(y) / (x + y + z) * (dfs(x, y + 1, z) + 1);
    res += (double)(z) / (x + y + z) * (dfs(x, y, z + 1) + 1);

    return dp[x][y][z] = res;
}

int main(void)
{
    ll a, b, c;
    cin >> a >> b >> c;

    printf("%.10lf\n", dfs(a, b, c));
}
