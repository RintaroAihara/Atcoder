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
#include <cassert>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

int main(void)
{
    ll n, m, q;
    cin >> n >> m >> q;

    ll ans = 0;

    vector<ll> a(n, 0), b(m, 0);
    multiset<ll> sa, sb;

    for (int i = 0; i < q; i++)
    {
        ll t, x, y;
        cin >> t >> x >> y;
        x--;

        if (t == 1)
        {
            sa.erase(sa.find(a[x]));
        }
        else
        {
        }
    }
}