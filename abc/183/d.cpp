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
    ll n, w;
    cin >> n >> w;

    vector<ll> a(200010, 0);

    for (int i = 0; i < n; i++)
    {
        ll s, t, p;
        cin >> s >> t >> p;

        a[s] += p;
        a[t] += -p;
    }

    for (int i = 0; i < 200001; i++)
    {
        a[i + 1] += a[i];
    }

    for (int i = 0; i < 200000; i++)
    {
        if (a[i] > w)
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
