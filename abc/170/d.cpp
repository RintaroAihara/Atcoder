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

    map<ll, ll> m;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        m[a]++;
    }

    set<int> s;
    for (int i = 1; i < 1000010; i++)
    {
        s.insert(i);
    }

    for (auto x : m)
    {
        for (int j = x.first * 2; j < 1000010; j += x.first)
        {
            s.erase(j);
        }
    }

    ll ans = 0;

    for (auto x : s)
    {
        if (m[x] == 1)
        {
            ans++;
        }
    }

    cout << ans << endl;
}
