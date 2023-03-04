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
    ll a, b, c, d, e;

    cin >> a >> b >> c >> d;

    e = lcm(c, d);

    cout << (b - (b / c + b / d - b / e)) - (a - 1 - (((a - 1) / c + (a - 1) / d - (a - 1) / e))) << endl;
}