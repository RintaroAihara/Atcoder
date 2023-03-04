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
    int n, m;

    cin >> n >> m;

    multiset<ll> a;
    map<ll, ll, greater<ll>> p;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        p[x]++;
    }

    for (int i = 0; i < m; i++)
    {
        int b, c;

        cin >> b >> c;

        p[c] += b;
    }

    int count = 0;

    ll ans = 0;

    for (auto z : p)
    {
        for (int i = 0; i < z.second; i++)
        {
            count++;

            if (count > n)
            {
                break;
            }

            ans += z.first;
        }
    }

    cout << ans << endl;
}