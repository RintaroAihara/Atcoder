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
    string s, t;
    cin >> s >> t;
    map<char, set<ll>> m;

    for (int i = 0; i < s.size(); i++)
    {
        m[s[i]].insert(i);
    }

    ll ans = 0;
    ll tmp = -1;
    ll n = 0;

    for (int i = 0; i < t.size(); i++)
    {
        if (m[t[i]].size() == 0)
        {
            cout << -1 << endl;
            return 0;
        }

        auto x = m[t[i]].upper_bound(tmp);

        if (x == m[t[i]].end())
        {
            n++;
            tmp = *m[t[i]].begin();
        }
        else
        {
            tmp = *x;
        }
    }

    cout << n * s.size() + tmp + 1 << endl;
}