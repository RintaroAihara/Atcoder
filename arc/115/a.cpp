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

    vector<ll> v(n);
    ll o = 0;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        ll x = 0;

        for (int j = 0; j < m; j++)
        {
            if (s[j] == '1')
            {
                x++;
            }
        }

        if (x % 2 == 1)
        {
            o++;
        }
    }

    ll ans = n * (n - 1) / 2;

    ans -= o * (o - 1) / 2;
    ll p = n - o;

    ans -= p * (p - 1) / 2;

    cout << ans << endl;
}