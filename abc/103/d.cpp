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

bool compair(P a, P b)
{
    return a.second < b.second;
}

int main(void)
{
    int n, m;
    cin >> n >> m;

    vector<P> ab(m);

    for (int i = 0; i < m; i++)
    {
        cin >> ab[i].first >> ab[i].second;
    }

    sort(ab.begin(), ab.end(), compair);

    int ans = 0, t = 0;

    for (int i = 0; i < m; i++)
    {
        if (t <= ab[i].first)
        {
            t = ab[i].second;
            ans++;
        }
    }

    cout << ans << endl;
}
