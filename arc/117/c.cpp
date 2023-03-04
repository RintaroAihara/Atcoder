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
#include <cassert>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

ll n;
vector<vector<char>> dp;

char dfs(ll x, ll y)
{
    if (dp[x][y] != '0')
    {
        return dp[x][y];
    }

    char c1 = dfs(x - 1, y), c2 = dfs(x - 1, y + 1);

    if ((c1 == 'B' && c2 == 'B') || (c1 == 'W' && c2 == 'R') || (c1 == 'R' && c2 == 'W'))
    {
        return dp[x][y] = 'B';
    }
    else if ((c1 == 'R' && c2 == 'R') || (c1 == 'B' && c2 == 'W') || (c1 == 'W' && c2 == 'B'))
    {
        return dp[x][y] = 'R';
    }
    else
    {
        return dp[x][y] = 'W';
    }
}

int main(void)
{
    string s;
    cin >> n >> s;
    dp.assign(n, vector<char>(n, '0'));

    for (int i = 0; i < n; i++)
    {
        dp[0][i] = s[i];
    }

    dfs(n - 1, 0);
}