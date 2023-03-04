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
    ll n;
    cin >> n;

    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll ans = INF;

    for (int i = 0; i < (1ll << (n - 1)); i++)
    {
        ll b = 0;
        ll x = 0;

        for (int j = 0; j < n - 1; j++)
        {
            b |= a[j];
            if (i & (1ll << j))
            {
                x ^= b;
                b = 0;
            }
        }

        b |= a[n - 1];

        x ^= b;

        chmin(ans, x);
    }

    cout << ans << endl;
}