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
    ll s;
    cin >> s;

    set<ll> a;

    ll x = s;
    a.insert(x);

    ll m = 1;

    while (1)
    {
        m++;
        if (x & 1)
        {
            x = 3 * x + 1;
        }
        else
        {
            x /= 2;
        }

        if (a.find(x) != a.end())
        {
            break;
        }
        else
        {
            a.insert(x);
        }
    }

    cout << m << endl;
}
