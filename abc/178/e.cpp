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
    ll n;
    cin >> n;

    vector<ll> x(n), y(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    set<ll> pp, pm, mp, mm;

    for (int i = 0; i < n; i++)
    {
        pp.insert(x[i] + y[i]);
        pm.insert(x[i] - y[i]);
        mp.insert(-x[i] + y[i]);
        mm.insert(-x[i] - y[i]);
    }

    cout << max({*pp.rbegin() - *pp.begin(), *pm.rbegin() - *pm.begin(), *mp.rbegin() - *mp.begin(), *mm.rbegin() - *mm.begin()}) << endl;
    ;
}
