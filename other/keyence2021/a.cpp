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

    vector<ll> a(n), b(n), ma(n), c(n);
    vector<P> mb(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ma[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        ma[i] = max(a[i], ma[i - 1]);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    c[0] = a[0] * b[0];

    for (int i = 1; i < n; i++)
    {
        c[i] = max(c[i - 1], b[i] * ma[i]);
    }

    for (auto &&i : c)
    {
        cout << i << endl;
    }
}