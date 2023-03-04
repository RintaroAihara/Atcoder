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

    vector<ll> a(n);

    ll ans = INF;
    map<ll, ll> ma;
    ll r = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ma[a[i]]++;

        if (i == m - 1)
        {
            for (auto &&j : ma)
            {
                if (r == j.first)
                {
                    r++;
                }
            }
        }

        if (i >= m)
        {
            ma[a[i - m]]--;

            if (ma[a[i - m]] == 0 && a[i - m] < r)
            {
                r = a[i - m];
            }
        }

        if (i >= m - 1)
        {
            chmin(ans, r);
        }
    }

    cout << ans << endl;
}