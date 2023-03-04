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
#include <stack>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    int n, q;
    cin >> n >> q;

    vector<vector<int>> g(n, vector<int>());
    vector<ll> c(n, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 0; i < q; i++)
    {
        int p, x;
        cin >> p >> x;
        p--;
        c[p] += x;
    }

    queue<int> que;
    que.push(0);
    vector<int> searched(n, false);

    while (que.size())
    {
        ll z = que.front();
        que.pop();
        searched[z] = true;

        for (auto &&i : g[z])
        {
            if (!searched[i])
            {
                c[i] += c[z];
                que.push(i);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << c[i] << endl;
    }
}