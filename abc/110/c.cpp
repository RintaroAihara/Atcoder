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

    map<char, ll> sc, tc;

    for (int i = 0; i < s.size(); i++)
    {
        sc[s[i]]++;
    }

    for (int i = 0; i < t.size(); i++)
    {
        tc[t[i]]++;
    }

    map<ll, ll> s1, t1;

    for (auto x : sc)
    {
        s1[x.second]++;
    }

    for (auto x : tc)
    {
        t1[x.second]++;
    }

    for (int i = 0; i <= s.size(); i++)
    {
        if (s1[i] != t1[i])
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
