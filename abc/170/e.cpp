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
#include <cassert>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

int main(void)
{
    ll n, q;
    cin >> n >> q;

    vector<ll> rate(200010, 0), garden(200010, 0);
    vector<multiset<ll>> s(200010);
    multiset<ll> mini;

    for (int i = 1; i <= n; i++)
    {
        cin >> rate[i] >> garden[i];

        s[garden[i]].insert(rate[i]);
    }

    for (int i = 0; i < 200010; i++)
    {
        if (s[i].size())
        {
            mini.insert(*s[i].rbegin());
        }
    }

    for (int i = 0; i < q; i++)
    {
        ll c, d;
        cin >> c >> d;

        if (s[garden[c]].size())
        {
            mini.erase(mini.find(*s[garden[c]].rbegin()));
        }

        if (s[d].size())
        {
            mini.erase(mini.find(*s[d].rbegin()));
        }

        s[garden[c]].erase(s[garden[c]].find(rate[c]));
        s[d].insert(rate[c]);
        if (s[garden[c]].size())
        {
            mini.insert(*s[garden[c]].rbegin());
        }

        mini.insert(*s[d].rbegin());
        garden[c] = d;

        cout << *mini.begin() << endl;
    }
}