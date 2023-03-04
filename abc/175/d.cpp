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
    ll ans = -INF;
    cin >> n >> k;

    vector<ll> p(n), c(n);

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    for (int i = 0; i < n; i++)
    {
        ll cycle_sum = 0;
        ll next_i = i;
        ll cycle_cnt = 0;

        while (true)
        {
            cycle_cnt++;
            next_i = p[next_i];
            cycle_sum += c[next_i];
            if (next_i == i)
            {
                break;
            }
        }

        next_i = i;
        ll cnt = 0;
        ll path = 0;

        while (true)
        {
            cnt++;
            path += c[next_i];

            if (cnt > k)
            {
                break;
            }

            ll score = path + max(0ll, cycle_sum) * ((k - cnt) / cycle_cnt);

            ans = max(ans, score);

            next_i = p[next_i];

            if (next_i == i)
            {
                break;
            }
        }
    }

    cout << ans << endl;
}
