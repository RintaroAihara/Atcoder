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
    ll k, n;
    ll s = 0;
    cin >> k >> n;

    vector<ll> a(n);

    cin >> a[0];

    for (int i = 1; i < n; i++)
    {
        cin >> a[i];

        s = max(s, a[i] - a[i - 1]);
    }

    s = max(s, k - a[n - 1] + a[0]);

    cout << k - s << endl;
}