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
    ll n, x, y;
    vector<ll> G[3000];

    cin >> n >> x >> y;
    x--;
    y--;

    vector<int> ans(n);

    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            ans[min({j - i, abs(j - y) + abs(x - i) + 1, abs(i - x) + abs(y - j) + 1})]++;
        }
    }

    for (int i = 1; i < n; i++)
    {
        cout << ans[i] << endl;
    }
}