#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
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

int main(void)
{
    ll n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> G(n, vector<ll>());

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<ll> c(n);

    for (int i = 0; i < n; i++)
    {
        int x;

        cin >> c[i];
    }

    for (int i = 0; i < q; i++)
    {
        int s;
        cin >> s;

        if (s == 1)
        {
            int x;
            cin >> x;
            x--;
            cout << c[x] << endl;

            for (auto p : G[x])
            {
                c[p] = c[x];
            }
        }
        else
        {
            int x, y;
            cin >> x >> y;
            x--;

            cout << c[x] << endl;

            c[x] = y;
        }
    }
}
