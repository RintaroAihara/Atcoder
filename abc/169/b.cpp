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
    int n;
    cin >> n;

    ll ans = 1;

    ll r = 1e18;

    vector<ll> a(n);

    for (auto &x : a)
    {
        cin >> x;
        if (x == 0)
        {
            cout << 0 << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (1000000000000000000 / ans < a[i])
        {
            cout << -1 << endl;
            return 0;
        }

        ans *= a[i];
    }

    cout << ans << endl;
}
