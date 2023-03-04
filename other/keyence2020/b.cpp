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
    int n;
    cin >> n;
    vector<P> a;

    for (int i = 0; i < n; i++)
    {
        ll x, l;
        cin >> x >> l;
        a.push_back({x + l, x - l});
    }

    sort(a.begin(), a.end());
    ll t = -INF;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (t <= a[i].second)
        {
            ans++;
            t = a[i].first;
        }
    }

    cout << ans << endl;
}