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

set<ll> divisor(ll n)
{
    set<ll> ret;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ret.insert(i);
            if (i * i != n)
                ret.insert(n / i);
        }
    }

    return (ret);
}

int main(void)
{
    int n;
    cin >> n;

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (divisor(i).size() == 8 && i & 1)
        {
            ans++;
        }
    }

    cout << ans << endl;
}
