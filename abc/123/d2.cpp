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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    int x, y, z, k;

    cin >> x >> y >> z >> k;

    vector<ll> a(x), b(y), c(z), ab, ans;

    for (int i = 0; i < x; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < y; i++)
    {
        cin >> b[i];
    }

    for (int i = 0; i < z; i++)
    {
        cin >> c[i];
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            ab.push_back(a[i] + b[j]);
        }
    }

    sort(ab.rbegin(), ab.rend());

    for (int i = 0; i < min(k, x * y); i++)
    {
        for (int j = 0; j < z; j++)
        {
            ans.push_back(ab[i] + c[j]);
        }
    }

    sort(ans.rbegin(), ans.rend());

    for (int i = 0; i < k; i++)
    {
        cout << ans[i] << endl;
    }
}