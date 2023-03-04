#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 62) - 1;

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

vector<P> factorization(ll n)
{
    vector<P> p;
    ll i;

    for (i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            if (p.empty())
            {
                p.push_back(P(i, 1));
            }

            if (p.empty() || p.back().first != i)
            {
                p.push_back(P(i, 1));
            }
            else
            {
                p.back().second++;
            }

            n /= i;
        }
    }

    if (n != 1)
    {
        p.push_back(P(n, 1));
    }

    return p;
}

int main(void)
{
    ll a, b;
    ll g;
    vector<P> p;

    cin >> a >> b;

    g = gcd(a, b);

    p = factorization(g);

    cout << p.size() + 1 << endl;
}