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
    ll a, b, m;
    ll x, y, c;
    ll mina = INF, minb = INF, minsum = INF;
    cin >> a >> b >> m;

    vector<ll> va(a + 1), vb(b + 1);

    for (int i = 1; i <= a; i++)
    {
        cin >> va[i];

        mina = min(mina, va[i]);
    }

    for (int i = 1; i <= b; i++)
    {
        cin >> vb[i];
        minb = min(minb, vb[i]);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> c;

        minsum = min(minsum, va[x] + vb[y] - c);
    }

    cout << min(minsum, mina + minb) << endl;
}