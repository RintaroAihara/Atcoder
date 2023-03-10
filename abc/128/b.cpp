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

    set<tuple<string, ll, ll>> r;

    string s;
    int p;

    for (int i = 0; i < n; i++)
    {
        cin >> s >> p;
        p *= -1;
        r.insert(make_tuple(s, p, i + 1));
    }

    for (auto x : r)
    {
        cout << get<2>(x) << endl;
    }
}