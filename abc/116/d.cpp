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

    priority_queue<P, vector<P>, greater<P>> s;
    priority_queue<P> p;
    set<ll> se;

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        ll t, d;

        cin >> t >> d;

        p.push({d, t});
    }

    for (int i = 0; i < k; i++)
    {
        s.push(p.top());
        ans += p.top().first;
        se.insert(p.top().second);
        p.pop();
    }

    ans += pow(se.size(), 2);

    cout << ans << endl;
}
