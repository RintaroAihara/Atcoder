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
    ll x;
    ll a, b;

    cin >> x;

    for (ll i = -1000; i <= 1000; i++)
    {
        for (ll j = -1000; j <= 1000; j++)
        {
            a = pow(i, 5);
            b = pow(j, 5);

            if (a - b == x)
            {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
}
