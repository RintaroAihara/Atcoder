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

ll ans = 0;
ll h, w, a, b;

void dfs(ll able, ll d, ll c)
{
    if (able & (1ll << d))
    {
        dfs(able, d + 1, c);
        return;
    }

    if (d == h * w)
    {
        if (b == c)
        {
            ans++;
        }

        return;
    }

    dfs(able | (1ll << d), d + 1, c + 1);

    ll x = d + 1, y = d + w;

    if (x < h * w)
    {
        if (x / w == d / w)
        {
            if (able & (1ll << x))
            {
            }
            else
            {
                ll tmp = able | (1ll << d);
                tmp |= (1ll << x);
                dfs(tmp, d + 1, c);
            }
        }
    }

    if (y < h * w)
    {
        if (able & (1ll << y))
        {
        }
        else
        {
            ll tmp = able | (1ll << d);
            tmp |= (1ll << y);
            dfs(tmp, d + 1, c);
        }
    }
}

int main(void)
{
    cin >> h >> w >> a >> b;

    dfs(0ll, 0ll, 0ll);

    cout << ans << endl;
}