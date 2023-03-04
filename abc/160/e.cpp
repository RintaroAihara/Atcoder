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
    ll x, y, a, b, c;
    ll n;
    priority_queue<ll> sum;
    ll ans = 0;

    cin >> x >> y >> a >> b >> c;

    priority_queue<ll> p, q, r;

    for (int i = 0; i < a; i++)
    {
        cin >> n;
        p.push(n);
    }

    for (int i = 0; i < x; i++)
    {
        sum.push(p.top());
        p.pop();
    }

    for (int i = 0; i < b; i++)
    {
        cin >> n;
        q.push(n);
    }

    for (int i = 0; i < y; i++)
    {
        sum.push(q.top());
        q.pop();
    }

    for (int i = 0; i < c; i++)
    {
        cin >> n;
        sum.push(n);
    }

    for (int i = 0; i < x + y; i++)
    {
        ans += sum.top();
        sum.pop();
    }

    cout << ans << endl;
}