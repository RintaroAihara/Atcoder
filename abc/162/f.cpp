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

    ll ans = 0;

    if (n % 2 == 0)
    {
        ll tmp = 0;

        for (int i = 0; i < n; i += 2)
        {
            tmp += a[i];
        }

        chmax(ans, tmp);
        tmp = 0;

        for (int i = 1; i < n; i += 2)
        {
            tmp += a[i];
        }

        chmax(ans, tmp);
    }
    else
    {
        vector<ll> s1(n + 1, 0), s2(n + 1, 0), s3(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                s1[i + 1] = s1[i] + a[i];
                s2[i + 1] = s2[i];
            }
            else
            {
                s2[i + 1] = s2[i] + a[i];
                s1[i + 1] = s1[i];
            }
        }

        for (int i = 2; i < n; i++)
        {
            
        }
        

        for (int i = 0; i < n - 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                ll tmp = 0;

                tmp += a[i + j];

                tmp += max(s1[n] - s1[i + 4], s2[n] - s2[i + 4]);
            }
        }
    }

    cout << ans << endl;
}