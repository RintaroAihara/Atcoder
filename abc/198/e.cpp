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

ll n;
vector<ll> c, cnt;
vector<vector<ll>> g;
vector<ll> ans;

void dfs(int v)
{
    ans[v] = (cnt[c[v]] == 0);
    cnt[c[v]]++;

    for (auto &&i : g[v])
    {
        if (ans[i] == -1)
        {
            dfs(i);
        }
    }

    cnt[c[v]]--;
}

int main(void)
{
    cin >> n;
    c.assign(n, 0);
    cnt.assign(100010, 0);
    ans.assign(n, -1);
    g.assign(n, vector<ll>());

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0);

    for (int i = 0; i < n; i++)
    {
        if (ans[i] == 1)
        {
            cout << i + 1 << endl;
        }
    }
}