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

    vector<pair<string, ll>> m;

    for (int i = 0; i < n; i++)
    {
        string s;
        ll t;
        cin >> s >> t;

        m.push_back({s, t});
    }

    string x;
    cin >> x;

    bool f = false;

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (f)
        {
            ans += m[i].second;
        }

        if (m[i].first == x)
        {
            f = true;
        }
    }

    cout << ans << endl;
}