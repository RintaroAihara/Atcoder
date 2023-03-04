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
    ll k;
    cin >> k;
    vector<ll> a(k);

    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }

    ll l = 2, r = 2;

    for (int i = k - 1; i >= 0; i--)
    {
        r = r / a[i] * a[i];

        if (l / a[i] == 0)
        {
            l = a[i];
        }

        if (l > r)
        {
            cout << -1 << endl;
            return 0;
        }

        r = (r / a[i] + 1ll) * a[i] - 1ll;
        l = (l + a[i] - 1ll) / a[i] * a[i];
    }

    cout << l << " " << r << endl;
}
