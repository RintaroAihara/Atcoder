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
    int n;
    cin >> n;

    priority_queue<P, vector<P>, greater<P>> blue;
    priority_queue<P> red;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        red.push({b, a});
    }

    for (int i = 0; i < n; i++)
    {
        int c, d;
        cin >> c >> d;

        blue.push({c, d});
    }

    ll ans = 0;

    while (blue.size())
    {
        P b = blue.top();
        blue.pop();

        queue<P> q;

        while (red.size())
        {
            P r = red.top();
            red.pop();

            if (r.first < b.second && r.second < b.first)
            {
                ans++;
                break;
            }
            else
            {
                q.push(r);
            }
        }

        while (q.size())
        {
            red.push(q.front());
            q.pop();
        }
    }

    cout << ans << endl;
}
