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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

vector<vector<P>> G;

vector<int> ans;

void dfs(int v, int p, int c)
{
    ans[v] = c;

    for (auto x : G[v])
    {
        if (x.first == p)
        {
            continue;
        }

        if (x.second % 2 == 0)
        {
            dfs(x.first, v, c);
        }
        else
        {
            dfs(x.first, v, 1 - c);
        }
    }
}

int main(void)
{
    int n;
    int u, v, w;

    cin >> n;

    G.assign(n, vector<P>());

    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> w;
        u--;
        v--;

        G[u].push_back(P(v, w));
        G[v].push_back(P(u, w));
    }

    ans.assign(n, 0);

    dfs(0, -1, 1);

    for (auto x : ans)
    {
        cout << x << endl;
    }
}