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
    ll n, m, x;

    cin >> n >> m >> x;

    vector<ll> c(n);

    ll a[20][20];

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];

        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    ll ans = INF;

    for (int i = 0; i < (1 << n); i++)
    {
        vector<ll> tmp(m, 0);
        ll sum = 0;

        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                sum += c[j];

                for (int k = 0; k < m; k++)
                {
                    tmp[k] += a[j][k];
                }
            }
        }

        bool flag = true;

        for (int j = 0; j < m; j++)
        {
            if (tmp[j] < x)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            ans = min(ans, sum);
        }
    }

    if (ans == INF)
    {
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;
}
