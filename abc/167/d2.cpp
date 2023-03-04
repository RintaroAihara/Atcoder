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

    vector<ll> a(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int ans = 1;

    while (k)
    {
        if (k & 1)
        {
            ans = a[ans];
        }

        vector<ll> d(n + 1);

        for (int i = 1; i <= n; i++)
        {
            d[i] = a[a[i]];
        }

        a = d;

        k >>= 1;
    }

    cout << ans << endl;
}