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
    ll n, m;
    cin >> n >> m;

    if (n == 1 && m == 0)
    {
        printf("%d %d\n", 1, 10000000);
        return 0;
    }
    

    if (m < 0 || m >= n - 1)
    {
        cout << -1 << endl;
        return 0;
    }

    printf("%d %d\n", 1, 10000000);

    ll l = 2, r = 3;

    for (int i = 0; i < m + 1; i++)
    {
        printf("%lld %lld\n", l, r);
        l += 2;
        r += 2;
    }

    l = 10000001, r = 10000002;

    for (int i = 0; i < n - (m + 2); i++)
    {
        printf("%lld %lld\n", l, r);
        l += 2;
        r += 2;
    }
}
