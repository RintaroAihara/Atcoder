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

int main(void)
{
    ll n;
    cin >> n;

    vector<vector<ll>> g(n, vector<ll>());
    vector<ll> n_child(n);
    vector<ll> parent(n);
    vector<pair<priority_queue<pair<ll, ll>>, priority_queue<pair<ll, ll>>>> q;

    ll ans = 1;
    parent[0] = -1;

    for (int i = 1; i < n; i++)
    {
        ll p;
        cin >> p;
        p--;

        parent[i] = p;
        g[p].push_back(i);
    }
}