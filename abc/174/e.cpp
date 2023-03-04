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
    ll n, k;
    cin >> n >> k;

    ll l = 0, r = INF;

    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    while (r - l > 1)
    {
        ll mid = (r + l) / 2;

        ll count = 0;

        for (ll i = 0; i < n; i++)
        {
            if (a[i] % mid == 0)
            {
                count += a[i] / mid - 1;
            }
            else
            {
                count += a[i] / mid;
            }
        }

        if (count <= k)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }

    cout << r << endl;
}
