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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    int n, k;
    cin >> n >> k;

    vector<ll> v(n);

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int l = 0; l < n; l++)
    {
        for (int r = l; r <= n; r++)
        {
            int res = 0;
            vector<int> q;
            ll sum = 0;

            for (int i = 0; i < n; i++)
            {
                if (i < l || r <= i)
                {
                    q.push_back(v[i]);
                    sum += v[i];
                }
            }

            sort(q.begin(), q.end());

            if (k < l + n - r)
            {
                continue;
            }

            for (int i = 0; i < k - (l + n - r) && i < q.size(); i++)
            {
                if (q[i] > 0)
                {
                    break;
                }

                sum -= q[i];
            }

            ans = max(ans, sum);
        }
    }

    cout << ans << endl;
}