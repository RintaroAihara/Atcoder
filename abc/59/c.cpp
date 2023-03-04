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

    ll s1 = 0, s2 = 0;
    ll ans1 = 0, ans2 = 0;

    for (int i = 0; i < n; i++)
    {
        s1 += a[i];
        s2 += a[i];
        if (i & 1)
        {
            if (s1 >= 0)
            {
                ans1 += abs(-1 - s1);
                s1 = -1;
            }

            if (s2 <= 0)
            {
                ans2 += abs(1 - s2);
                s2 = 1;
            }
        }
        else
        {
            if (s1 <= 0)
            {
                ans1 += abs(1 - s1);
                s1 = 1;
            }

            if (s2 >= 0)
            {
                ans2 += abs(-1 - s2);
                s2 = -1;
            }
        }
    }

    cout << min(ans1, ans2) << endl;
}