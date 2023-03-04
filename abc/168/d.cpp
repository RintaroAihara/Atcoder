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

int main(void)
{
    ll n, m;

    cin >> n >> m;

    vector<ll> ans(n + 1, -1);

    vector<vector<ll>> G(n + 1, vector<ll>());

    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    queue<ll> q;
    q.push(1);

    while (q.size())
    {
        ll p = q.front();
        q.pop();

        for (auto x : G[p])
        {
            if (ans[x] == -1)
            {
                ans[x] = p;
                q.push(x);
            }
        }
    }

    cout << "Yes" << endl;

    for (int i = 2; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
}
