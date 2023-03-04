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
    ll n, k, L;
    cin >> n >> L >> k;

    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll l = -1, r = L + 1;

    while (r - l > 1)
    {
        ll mid = (r + l) / 2;

        ll c = 0;
        ll tmp = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] - tmp >= mid)
            {
                c++;
                tmp = a[i];

                if (c == k)
                {
                    break;
                }
            }
        }

        if (c < k || L - tmp < mid)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }

    cout << l << endl;
}