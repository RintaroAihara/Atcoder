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
    ll n, m, k;
    cin >> n >> m;

    vector<ll> a(m), b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }

    cin >> k;

    vector<ll> c(k), d(k);

    for (int i = 0; i < k; i++)
    {
        cin >> c[i] >> d[i];
        c[i]--;
        d[i]--;
    }

    ll ans = 0;

    for (int i = 0; i < (1 << k); i++)
    {
        vector<bool> dish(n, false);

        for (int j = 0; j < k; j++)
        {
            if (i & (1 << j))
            {
                dish[c[j]] = true;
            }
            else
            {
                dish[d[j]] = true;
            }
        }

        ll tmp = 0;

        for (int j = 0; j < m; j++)
        {
            if (dish[a[j]] && dish[b[j]])
            {
                tmp++;
            }
        }

        ans = max(tmp, ans);
    }

    cout << ans << endl;
}
