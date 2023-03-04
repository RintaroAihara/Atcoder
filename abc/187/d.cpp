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
    ll n;
    cin >> n;
    priority_queue<ll> q;

    ll A = 0;

    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        A += a;
        q.push(a * 2 + b);
    }

    ll ans = 0;
    ll B = 0;

    while (true)
    {
        if (A < B)
        {
            cout << ans << endl;
            return 0;
        }

        ll p = q.top();
        q.pop();
        B += p;
        ans++;
    }
}
