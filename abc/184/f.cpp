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
    ll n, t;
    cin >> n >> t;

    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<ll> x, y;

    for (int i = 0; i < (1 << (n / 2)); i++)
    {
        ll tmp = 0;
        for (int j = 0; j < n / 2; j++)
        {
            if (i & (1 << j))
            {
                tmp += a[j];
            }
        }

        x.push_back(tmp);
    }

    for (int i = 0; i < (1 << (n - n / 2)); i++)
    {
        ll tmp = 0;
        for (int j = 0; j < n - n / 2; j++)
        {
            if (i & (1 << j))
            {
                tmp += a[j + n / 2];
            }
        }

        y.push_back(tmp);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    ll ans = 0;

    for (int i = 0; i < x.size(); i++)
    {
        if (t - x[i] < 0)
        {
            continue;
        }

        auto itr = upper_bound(y.begin(), y.end(), t - x[i]);

        itr--;
        if (x[i] + *itr <= t)
        {
            chmax(ans, x[i] + *itr);
        }
    }

    cout << ans << endl;
}
