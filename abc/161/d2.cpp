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
    ll k;
    cin >> k;

    queue<ll> q;

    for (int i = 1; i < 10; i++)
    {
        q.push(i);
    }

    for (int i = 1; i < 100010; i++)
    {
        ll ans = q.front();
        q.pop();

        if (i == k)
        {
            cout << ans << endl;
            break;
        }

        if (ans % 10 - 1 >= 0)
        {
            q.push(10 * ans + ans % 10 - 1);
        }

        q.push(10 * ans + ans % 10);

        if (ans % 10 + 1 < 10)
        {
            q.push(10 * ans + ans % 10 + 1);
        }
    }

}