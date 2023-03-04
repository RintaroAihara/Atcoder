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
    ll x, m, t, n;

    cin >> x >> m >> t;
    n = x;

    ll a, b, c = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        n -= a - c;

        if (n <= 0)
        {
            cout << "No" << endl;
            return 0;
        }

        n = min(n + b - a, x);

        c = b;
    }

    n -= t - b;
    if (n <= 0)
    {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
}
