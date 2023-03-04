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

inline ll mod(ll a, ll m)
{
    return (a % m + m) % m;
}

// ax+by=dとなるような最小のd=gcd(a,b)を出力
ll extGCD(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a % b, y, x);
    y -= a / b * x;

    return d;
}

ll modinv(ll a, ll m)
{
    ll x, y;
    extGCD(a, m, x, y);
    return mod(x, m);
}

//ax+b=cy+d=z (x,y>=0)となるような最小のzを求める.
//解が存在しない場合、-1を返す
ll crt(ll a, ll b, ll c, ll d)
{
    ll g = gcd(a, c);
    ll _a = a / g, _c = c / g;
    ll e = (b - d);

    if (e % g != 0)
    {
        return -1;
    }

    e /= g;

    ll y = mod(e * modinv(_c, _a), _a);
    ll z = c * y + d;

    return z;
}

int main(void)
{
    ll t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        ll x, y, p, q;
        cin >> x >> y >> p >> q;

        ll ans = INF;

        for (int i = 0; i < y; i++)
        {
            ll a = (x + y) * 2, b = x + i, c = p + q, d = p;
            ll tmp = crt(a, b, c, d);

            if (tmp != -1)
            {
                chmin(ans, tmp);
            }
        }

        for (int i = 0; i < q; i++)
        {
            ll a = (x + y) * 2, b = x, c = p + q, d = p + i;
            ll tmp = crt(a, b, c, d);

            if (tmp != -1)
            {
                chmin(ans, tmp);
            }
        }

        if (ans == INF)
        {
            cout << "infinity" << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
}