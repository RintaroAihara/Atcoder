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

    vector<ll> a(n), sum(n + 1, 0);
    ll s = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i] * a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        sum[i + 1] = sum[i] + a[i];
    }

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        s -= a[i] * a[i];
        ans += s;
        ans += (sum[n] - sum[i + 1]) * a[i] * -2ll + a[i] * a[i] * (n - i - 1);
    }

    cout << ans << endl;
}