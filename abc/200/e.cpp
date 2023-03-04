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

    ll s;

    for (ll i = 0; i < 3 * n - 3 + 1; i++)
    {
        if (k < i * (i + 1ll) * (i + 2ll) / 6ll)
        {
            s = i - 1 + 3;
            k -= (i - 1ll) * i * (i + 1ll) / 6ll;
        }
    }

    cout << s << endl;
    cout << k << endl;

    ll m = max(s - n * 2, 1ll);

    ll m2 = max(s - m - n, 1ll);
}