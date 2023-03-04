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
const ll MOD = 998244353;
const ll INF = (1ll << 60);

int main(void)
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= k; i++)
    {
        ll ans = 0;
        for (int j = 0; j < n; j++)
        {
            for (int l = j + 1; l < n; l++)
            {
                ans += pow(a[j] + a[l], i);
            }
        }

        cout << ans << endl;
    }
}
