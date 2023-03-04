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
    ll n, k;
    cin >> n >> k;
    vector<ll> s(n);

    bool b = false;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];

        if (!s[i])
        {
            b = true;
        }
    }

    if (b)
    {
        cout << n << endl;
        return 0;
    }

    ll ans = 0;
    ll m = 1;

    for (ll i = 0, j = 0; i < n; i++)
    {
        while (j < n && m * s[j] <= k)
        {
            m *= s[j];
            j++;
        }

        chmax(ans, j - i);

        if (i == j)
        {
            j++;
        }
        else
        {
            m /= s[i];
        }
    }

    cout << ans << endl;
}