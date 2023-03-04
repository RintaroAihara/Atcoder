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

int main(void)
{
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    ll x, y;
    x = abs(r2 - r1);
    y = abs(c2 - c1);

    if (x == 0 && y == 0)
    {
        cout << 0 << endl;
    }
    else if (x == y || x + y <= 3)
    {
        cout << 1 << endl;
    }
    else if ((x + y) % 2 == 0 || x + y <= 6 || abs(x - y) <= 3)
    {
        cout << 2 << endl;
    }
    else
    {
        cout << 3 << endl;
    }
}
