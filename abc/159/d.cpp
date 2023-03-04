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
    int n;
    ll ans = 0;

    cin >> n;

    vector<int> a(n);
    map<ll, ll> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
    }

    for (auto x : m)
    {
        ans += x.second * (x.second - 1) / 2;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans - m[a[i]] * (m[a[i]] - 1) / 2 + (m[a[i]] - 1) * (m[a[i]] - 2) / 2 << endl;
    }
}