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
    ll x, k, d;
    cin >> x >> k >> d;

    if (abs(x / d) + 1 <= k)
    {
        if ((k - x / d) % 2 == 0)
        {
            cout << abs(abs(x) - abs(d) * abs(x / d)) << endl;
        }
        else
        {
            cout << abs(abs(x) - abs(d) * (abs(x / d) + 1)) << endl;
        }
    }
    else
    {
        cout << abs(x) - abs(d) * k << endl;
    }
}
