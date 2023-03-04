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
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    ll n;
    cin >> n;
    vector<ll> t(n), a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> a[i];
    }

    ll T = t[0], A = a[0];

    for (int i = 1; i < n; i++)
    {
        ll k = max((A + a[i] - 1) / a[i], (T + t[i] - 1) / t[i]);

        A = a[i] * k;
        T = t[i] * k;
    }

    cout << T + A << endl;
}