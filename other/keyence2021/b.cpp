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
    ll n, k;
    cin >> n >> k;

    map<ll, ll> m;

    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        m[a]++;
    }

    ll ans = 0;
    ll x = min(m[0], k);

    for (int i = 1; i < n; i++)
    {
        if (x > min(m[i], k))
        {
            ans += (x - m[i]) * i;
            x = m[i];
        }
    }

    cout << ans << endl;
}