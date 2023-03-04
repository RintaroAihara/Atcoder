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
    int n;
    cin >> n;

    vector<int> a(n);

    for (auto &&i : a)
    {
        cin >> i;
    }

    sort(a.rbegin(), a.rend());

    ll ans = a[0];

    int idx = 1;

    for (int i = 2; i < n; i++)
    {
        ans += a[idx];
        if (i % 2 == 1)
            idx++;
    }
    cout << ans << "\n";
    return 0;

    cout << ans << endl;
}
