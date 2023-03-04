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
    ll k, x, y;
    cin >> k >> x >> y;

    queue<P> q;
    q.push(P(0, 0));
    ll count = 0;

    while (1)
    {
        P p = q.front();
        q.pop();

        for (ll i = -k; i <= k; i++)
        {
            for (ll j = -(k - abs(i)); abs(j) + abs(i) <= k; j++)
            {
                if (x == i && y == j)
                {
                    cout << count << endl;
                }

                q.push(P(i, j));
            }
        }
    }
}