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

    vector<map<ll, ll>> a(n + 1);
    vector<P> ans(m + 1);

    for (int i = 0; i < m; i++)
    {
        ll p, y;

        cin >> p >> y;
        a[p].insert(make_pair(y, i + 1));
    }

    for (int i = 1; i <= n; i++)
    {
        int j = 1;
        for (auto x : a[i])
        {
            ans[x.second] = P(i, j);
            j++;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        string x, y;

        x = to_string(ans[i].first);
        y = to_string(ans[i].second);

        while (x.size() < 6)
        {
            x.insert(x.begin(), '0');
        }

        while (y.size() < 6)
        {
            y.insert(y.begin(), '0');
        }

        cout << x + y << endl;
    }
}
