#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <queue>
#include <stack>
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1e9 + 7;

int main(void)
{
    int n;
    vector<int> a, b, c;
    int i, j;
    ll ans = 0;
    int bm;

    cin >> n;

    a.resize(n);
    b.resize(n);
    c.resize(n);

    rep(i, 0, n)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    rep(i, 0, n)
    {
        cin >> b[i];
    }

    sort(b.begin(), b.end());

    rep(i, 0, n)
    {
        cin >> c[i];
    }

    sort(c.begin(), c.end());

    rep(i, 0, n)
    {
        auto amin = lower_bound(a.begin(), a.end(), b[i]);

        auto cmin = upper_bound(c.begin(), c.end(), b[i]);

        ans += distance(a.begin(), amin) * distance(cmin, c.end());
    }

    cout << ans << endl;
}