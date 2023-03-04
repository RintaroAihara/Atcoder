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
    ll n, m;
    ll ans = 0;

    cin >> n >> m;

    if (n >= m)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<ll> x(m);
    priority_queue<ll> s;

    for (int i = 0; i < m; i++)
    {
        cin >> x[i];
    }

    sort(x.begin(), x.end());

    for (int i = 1; i < m; i++)
    {
        s.push(x[i] - x[i - 1]);
    }

    ans = *x.rbegin() - *x.begin();

    for (int i = 0; i < n - 1; i++)
    {
        ans -= s.top();
        s.pop();
    }

    cout << ans << endl;
}
