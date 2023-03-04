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

    vector<ll> h(n), w(m), s1(n + 1, 0), s2(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    sort(h.begin(), h.end());

    for (int i = 0; i < n / 2; i++)
    {
        s1[i + 1] = s1[i] + abs(h[2 * i] - h[2 * i + 1]);
    }

    for (int i = 0; i < n / 2; i++)
    {
        s2[i + 1] = s2[i] + abs(h[2 * i + 1] - h[2 * i + 2]);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> w[i];
    }

    ll ans = INF;

    for (int i = 0; i < m; i++)
    {
        int x = lower_bound(h.begin(), h.end(), w[i]) - h.begin();

        ll tmp = 0;

        if (x == 0)
        {
            tmp += abs(h[0] - w[i]);
            tmp += s2[n / 2] - s2[0];
        }
        else if (x == n)
        {
            tmp += abs(h[n - 1] - w[i]);
            tmp += s1[n / 2] - s1[0];
        }
        else
        {
            tmp += abs(h[x] - w[i]);

            if (x % 2)
            {
                tmp += abs(h[x + 1] - h[x - 1]);
                tmp += s2[n / 2] - s2[x / 2 + 1];
                tmp += s1[x / 2] - s1[0];
            }
            else
            {
                tmp += s2[n / 2] - s2[x / 2];
                tmp += s1[x / 2] - s1[0];
            }

            ans = min(tmp, ans);

            x--;
            tmp = 0;

            tmp += abs(h[x] - w[i]);

            if (x % 2)
            {
                tmp += abs(h[x + 1] - h[x - 1]);
                tmp += s2[n / 2] - s2[x / 2 + 1];
                tmp += s1[x / 2] - s1[0];
            }
            else
            {
                tmp += s2[n / 2] - s2[x / 2];
                tmp += s1[x / 2] - s1[0];
            }
        }

        ans = min(tmp, ans);
    }

    cout << ans << endl;
}
