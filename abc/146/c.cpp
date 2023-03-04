#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1e18) + 1;

ll digit(ll n)
{
    ll digit = 1;
    while (n / 10 > 0)
    {
        digit++;
        n /= 10;
    }

    return digit;
}

int main(void)
{
    ll a, b, x;
    ll n;

    cin >> a >> b >> x;

    ll ok = 0, ng = 1e9 + 1;

    while (ng - ok > 1)
    {
        n = (ng + ok) / 2;

        if (n * a + digit(n) * b <= x)
        {
            ok = n;
        }
        else
        {
            ng = n;
        }
    }

    cout << ok << endl;
}