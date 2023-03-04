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
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1e18) + 1;

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
    ll a, b;

    cin >> a >> b;

    cout << lcm(a, b) << endl;
}