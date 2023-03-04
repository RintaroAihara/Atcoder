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
#include <cassert>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> a(8, vector<ll>(n, 0));

    for (int i = 0; i < n; i++)
    {
        vector<ll> xyz(3);

        cin >> xyz[0] >> xyz[1] >> xyz[2];

        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (j & (1 << k))
                {
                    a[j][i] += xyz[k];
                }
                else
                {
                    a[j][i] -= xyz[k];
                }
            }
        }
    }

    ll ans = 0;

    for (int i = 0; i < 8; i++)
    {
        vector<ll> b = a[i];
        ll tmp = 0;

        sort(b.begin(), b.end(), greater<ll>());

        for (int j = m - 1; j >= 0; j--)
        {
            tmp += b[j];
        }

        ans = max(ans, tmp);
    }

    cout << ans << endl;
}