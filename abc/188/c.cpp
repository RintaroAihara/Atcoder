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

int n;

vector<P> rec(int x, vector<P> a)
{
    if (x == n - 1)
    {
        return a;
    }

    vector<P> res;

    for (int i = 0; i < a.size() / 2; i++)
    {
        if (a[2 * i].second > a[2 * i + 1].second)
        {
            res.push_back({a[2 * i].first, a[2 * i].second});
        }
        else
        {
            res.push_back({a[2 * i + 1].first, a[2 * i + 1].second});
        }
    }

    return rec(x + 1, res);
}

int main(void)
{
    cin >> n;
    vector<P> a(1 << n);

    for (int i = 0; i < 1 << n; i++)
    {
        cin >> a[i].second;
        a[i].first = i;
    }

    vector<P> ans;

    ans = rec(0, a);
    
    if (ans[0].second < ans[1].second)
    {
        cout << ans[0].first + 1 << endl;
    }
    else
    {
        cout << ans[1].first + 1 << endl;
    }
}
