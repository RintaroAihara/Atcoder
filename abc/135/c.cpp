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
    vector<int> a(n + 1), b(n);

    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        x = min(a[i], b[i]);
        ans += x;

        b[i] -= x;

        x = min(a[i + 1], b[i]);

        ans += x;

        a[i + 1] -= x;
    }

    cout << ans << endl;
}