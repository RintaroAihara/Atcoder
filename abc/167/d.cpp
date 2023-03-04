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

ll c = 0;
vector<ll> a(300000), b;
set<ll> p;
ll z;

void dfs(ll x)
{
    if (p.find(x) != p.end() && c > 0)
    {
        z = x;
        return;
    }

    p.insert(x);
    b.push_back(x);
    c++;
    dfs(a[x]);
}

int main(void)
{
    ll n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }

    dfs(0);

    ll t = 0;

    for (int i = 0; i < c; i++)
    {
        if (b[i] == z)
        {
            t = i;
            break;
        }
    }

    if (k - t <= 0)
    {
        cout << b[k] + 1 << endl;
        return 0;
    }

    cout << b[((k - t) % (c - t)) + t] + 1 << endl;
}
