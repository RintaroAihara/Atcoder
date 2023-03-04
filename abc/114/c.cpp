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

set<ll> ans;
ll n;

bool flag(ll a)
{
    bool f3, f5, f7, f = false;

    f3 = f5 = f7 = f = false;

    while (a)
    {
        if (a % 10 == 3)
        {
            f3 = true;
        }

        if (a % 10 == 5)
        {
            f5 = true;
        }

        if (a % 10 == 7)
        {
            f7 = true;
        }

        a /= 10;
    }

    if (f3 && f5 && f7)
    {
        f = true;
    }

    return f;
}

void dfs(ll a)
{
    if (a > n)
    {
        return;
    }

    if (flag(a))
    {
        ans.insert(a);
    }

    dfs(3 * pow(10, floor(log10(a)) + 1) + a);
    dfs(5 * pow(10, floor(log10(a)) + 1) + a);
    dfs(7 * pow(10, floor(log10(a)) + 1) + a);
}

int main(void)
{
    cin >> n;

    dfs(7);
    dfs(5);
    dfs(3);

    cout << ans.size() << endl;
}
