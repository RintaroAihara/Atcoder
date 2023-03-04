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

    vector<vector<ll>> sum(n + 1, vector<ll>(20, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            sum[i + 1][j] = sum[i][j] + ((a[i] >> j) & 1);
        }
    }

    ll x = 0;
    ll ans = 0;
    ll tmp = 0;

    ll l = 0, r = 1;

    while (r <= n)
    {
        bool flag = true;

        for (int j = 0; j < 20; j++)
        {
            if (sum[r][j] - sum[l][j] > 1)
            {
                flag = false;
            }
        }

        if (flag)
        {
            x = r - l;
            ans += x;
            r++;
        }
        else
        {
            tmp = 0;
            l++;
        }
    }

    cout << ans << endl;
}