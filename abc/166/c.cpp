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
    int n, m;
    cin >> n >> m;

    vector<ll> h(n);
    set<ll> G[n];

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;

        cin >> a >> b;
        a--;
        b--;

        G[a].insert(b);
        G[b].insert(a);
    }

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        bool flag = true;

        if (G[i].size())
        {
            for (auto x : G[i])
            {
                if (h[i] <= h[x])
                {
                    flag = false;
                }
            }

            if (flag)
            {
                ans++;
            }
        }
        else
        {
            ans++;
        }
    }

    cout << ans << endl;
}
