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

ll n, m, q;
vector<ll> a(100), b(100), c(100), d(100);
ll ans = 0;

void bfs(vector<ll> x)
{
    if (x.size() == n)
    {
        ll res = 0;

        for (ll k = 0; k < q; k++)
        {
            if (c[k] == x[b[k]] - x[a[k]])
            {
                res += d[k];
            }
        }

        ans = max(res, ans);

        return;
    }

    for (ll i = *x.rbegin(); i <= m; i++)
    {
        vector<ll> A = x;
        A.push_back(i);

        bfs(A);
    }
}

int main(void)
{
    cin >> n >> m >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--;
        b[i]--;
    }

    for (int i = 1; i <= m; i++)
    {
        vector<ll> A = {i};
        bfs(A);
    }

    cout << ans << endl;
}
