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

ll rec(ll n, ll x)
{
    if (n == 0)
    {
        return 1;
    }

    if (x == 1)
    {
        return 0;
    }

    ll p = pow(2, n) - 1;
    ll h = pow(2, n + 1) - 3;

    if (x <= h + 1)
    {
        return rec(n - 1, x - 1);
    }
    else if (x == h + 2)
    {
        return p + 1;
    }
    else if (x <= h * 2 + 2)
    {
        return p + 1 + rec(n - 1, x - h - 2);
    }
    else
    {
        return p * 2 + 1;
    }
}

int main(void)
{
    ll n, x;

    cin >> n >> x;

    cout << rec(n, x) << endl;
}
