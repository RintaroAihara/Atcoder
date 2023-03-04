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
    int n, q;

    int a, s;

    cin >> n >> q;

    vector<int> g(n);

    cin >> a;

    g[0] = a;

    for (int i = 1; i < n; i++)
    {
        cin >> a;
        g[i] = gcd(g[i - 1], a);
    }

    for (int i = 0; i < q; i++)
    {
        cin >> s;

        int ng = -1, ok = n;

        while (ok - ng > 1)
        {
            int mid = (ok + ng) / 2;

            if (gcd(g[mid], s) == 1)
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }

        if (ok == n)
        {
            cout << gcd(g[n - 1], s) << endl;
        }
        else
        {
            cout << ok + 1 << endl;
        }
    }
}