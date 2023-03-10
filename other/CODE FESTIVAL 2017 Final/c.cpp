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
    vector<int> d(n);

    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    sort(d.begin(), d.end());

    int ans = MOD;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans = min(ans, max({abs(d[i] - d[j]), abs(24 - d[i] - 24 + d[j]), abs(24 - d[i] - d[j]), abs(d[i] - 24 + d[j])}));
        }
    }

    if (ans == MOD)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}
