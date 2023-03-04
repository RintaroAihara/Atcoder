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
#include <stack>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    int n, m;
    int i;
    multiset<int> a;
    ll ans = 0;

    cin >> n >> m;

    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.insert(x);
    }

    for (i = 0; i < m; i++)
    {
        int k = *a.rbegin();

        a.erase(a.find(k));
        a.insert(k / 2);
    }

    for (auto x : a)
    {
        ans += x;
    }

    cout << ans << endl;
}