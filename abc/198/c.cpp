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
    ll r, x, y;
    cin >> r >> x >> y;

    ll a = -1, b = 1000000000ll;

    while (b - a > 1)
    {
        ll mid = (a + b) / 2;

        if (mid * mid >= x * x + y * y)
        {
            b = mid;
        }
        else
        {
            a = mid;
        }
    }

    if (b < r)
    {
        cout << 2 << endl;
    }
    else
    {
        cout << (b + r - 1) / r << endl;
    }
}