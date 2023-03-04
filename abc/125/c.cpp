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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

ll gcd(ll a, ll b)
{
    ll tmp;
    ll c;
    if (a < b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }

    do
    {
        c = a % b;
        a = b;
        b = c;
    } while (c != 0);

    return a;
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

int main(void)
{
    int n;

    cin >> n;

    vector<int> a(n), g(n), e;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    g[0] = a[0];

    e.push_back(0);

    ll ans = 0;

    for (int i = 1; i < n; i++)
    {
        g[i] = gcd(a[i], g[i - 1]);

        if (g[i] != g[i - 1])
        {
            e.push_back(i);
        }
    }

    for (auto x : e)
    {
        ll res;

        if (x == 0)
        {
            res = a[1];
        }
        else
        {
            res = a[0];
        }

        for (int i = 0; i < n; i++)
        {
            if (i == x)
            {
                continue;
            }

            res = gcd(res, a[i]);
        }

        ans = max(ans, res);
    }

    cout << ans << endl;
}