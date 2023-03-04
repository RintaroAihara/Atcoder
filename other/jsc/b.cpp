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
    ll n, m;
    cin >> n >> m;

    vector<bool> a(10000, false), b(10000, false);

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a[x] = true;
    }

    for (int i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        b[x] = true;
    }

    for (int i = 0; i < 1010; i++)
    {
        if (a[i] ^ b[i])
        {
            cout << i << endl;
        }
    }
}
