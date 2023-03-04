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
    ll a, b, q;

    cin >> a >> b >> q;

    vector<ll> s(a), t(b);
    ll x;

    for (int i = 0; i < a; i++)
    {
        cin >> s[i];
    }

    s.push_back(INF);
    s.push_back(-INF);
    sort(s.begin(), s.end());

    for (int i = 0; i < b; i++)
    {
        cin >> t[i];
    }

    t.push_back(INF);
    t.push_back(-INF);
    sort(t.begin(), t.end());

    for (int i = 0; i < q; i++)
    {
        cin >> x;
        ll ans = INF;

        int ds = lower_bound(s.begin(), s.end(), x) - s.begin();

        int dt = lower_bound(t.begin(), t.end(), x) - t.begin();

        for (int k = ds - 1; k <= ds; k++)
        {
            for (int j = dt - 1; j <= dt; j++)
            {
                ans = min(ans, abs(s[k] - x) + abs(s[k] - t[j]));
                ans = min(ans, abs(t[j] - x) + abs(s[k] - t[j]));
            }
        }

        cout << ans << endl;
    }
}
