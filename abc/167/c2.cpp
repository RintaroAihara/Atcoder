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

ll n, m, x;

vector<ll> c(n);

ll a[20][20];

int dfs(int x)
{
    if (x == n)
    {
        return 0;
    }

    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            return dfs(x);
        }
        else
        {
            return dfs(x) + c[x];
        }
    }
}

int main(void)
{

    cin >> n >> m >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];

        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
}
