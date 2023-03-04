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

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] -= i + 1;
    }

    sort(a.begin(), a.end());
    ll b;

    if (n & 1)
    {
        b = a[n / 2];
    }
    else
    {
        b = (a[n / 2] + a[n / 2 - 1]) / 2;
    }

    ll ans = 0;

    for (auto &&i : a)
    {
        ans += abs(i - b);
    }

    cout << ans << endl;
}