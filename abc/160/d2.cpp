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

int main(void)
{
    ll n, x, y;
    vector<ll> G[3000];

    cin >> n >> x >> y;
    x--;
    y--;

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
        {
            G[i].push_back(i + 1);
        }

        if (i + 1 < n)
        {
            G[i + 1].push_back(i);
        }
    }

    G[x].push_back(y);
    G[y].push_back(x);

    for (int i = 0; i < n; i++)
    {
        queue<ll> q;
        q.push(i);
        vector<ll> d(n, -1);
        d[i] = 0;

        while (q.size())
        {
            int p = q.front();
            q.pop();

            for (auto k : G[p])
            {
                if (d[k] == -1)
                {
                    q.push(k);
                    d[k] = d[p] + 1;
                    ans[d[k]]++;
                }
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        cout << ans[i] / 2 << endl;
    }
}