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
    double t, a;
    double tmp = 1000000000;

    cin >> n >> t >> a;

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        double h;
        cin >> h;

        if (tmp > abs(a - (t - 0.006 * h)))
        {
            tmp = abs(a - (t - 0.006 * h));
            ans = i + 1;
        }
    }

    cout << ans << endl;
}
