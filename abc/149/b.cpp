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
const ll INF = ll(1e18) + 1;

int main(void)
{
    ll a, b, k;

    cin >> a >> b >> k;

    a -= k;

    if (a < 0)
    {
        b += a;

        if (b < 0)
        {
            b = 0;
        }

        a = 0;
    }

    cout << a << " " << b << endl;
}