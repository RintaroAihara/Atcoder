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

map<ll, ll> prime_factor(ll n)
{
    map<ll, ll> ret;
    for (ll i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1)
        ret[n] = 1;
    return ret;
}

int main(void)
{
    int l;
    cin >> l;

    int n = 2, m = 0;

    int tmp = l;

    while (tmp > 3)
    {
        m += tmp % 2;
        m += 2;
        n++;
        tmp /= 2;
    }

    m += tmp;
    cout << n << " " << m << endl;

    int u = 1, v = 2;

    while (l > 3)
    {
        if (l % 2)
        {
            printf("%d %d %d\n", u, n, l - 1);
        }

        l /= 2;

        printf("%d %d %d\n", u, v, 0);
        printf("%d %d %d\n", u, v, l);
        u++, v++;
    }

    for (int i = 0; i < l; i++)
    {
        printf("%d %d %d\n", u, v, i);
    }
}