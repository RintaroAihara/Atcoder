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

    priority_queue<P, vector<P>, greater<P>> d;

    for (int i = 0; i < n; i++)
    {
        int x, y;

        cin >> x >> y;

        d.push(P(x, y));
    }

    while (d.size())
    {
        P p = d.top();
        d.pop();

        m -= p.second;

        if (m >= 0)
        {
            ans += p.first * p.second;
        }
        else
        {
            ans += p.first * (m + p.second);
            break;
        }
    }

    cout << ans << endl;
}