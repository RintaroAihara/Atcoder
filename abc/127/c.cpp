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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    int n, m;

    cin >> n >> m;

    vector<ll> sum(n + 1, 0);

    ll ans = 0;

    int l, r;

    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        l--;
        sum[l] += 1;
        sum[r] += -1;
    }

    for (int i = 0; i < n; i++)
    {
        sum[i + 1] += sum[i];

        if (sum[i] == m)
        {
            ans++;
        }
    }

    cout << ans << endl;
}