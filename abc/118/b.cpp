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
    int n, m, k, a;
    map<ll, ll> res;
    ll ans = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> k;

        for (int j = 0; j < k; j++)
        {
            cin >> a;
            res[a]++;
        }
    }

    for (auto x : res)
    {
        if (x.second == n)
        {
            ans++;
        }
    }

    cout << ans << endl;
}
