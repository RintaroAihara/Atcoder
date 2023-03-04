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
    ll n;
    cin >> n;

    ll ng = 2e9;
    ll ok = 0;

    while (ng - ok > 1)
    {
        ll mid = (ok + ng) / 2;
        ll sum = mid * (mid + 1) / 2;

        if (sum <= n + 1)
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }

    cout << n + 1 - ok << endl;
}
