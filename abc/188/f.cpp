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

map<ll, ll> m;

ll rec(ll x, ll y)
{
    if (m[y])
    {
        return m[y];
    }

    if (y == 1)
    {
        return m[y] = abs(x - y);
    }

    if (y & 1)
    {
        return m[y] = min({abs(x - y), rec(x, y + 1) + 1, rec(x, y - 1) + 1});
    }
    else
    {
        return m[y] = min(abs(x - y), rec(x, y / 2) + 1);
    }
}

int main(void)
{
    ll x, y;
    cin >> x >> y;

    if (x >= y)
    {
        cout << x - y << endl;
        return 0;
    }

    cout << rec(x, y) << endl;
}
