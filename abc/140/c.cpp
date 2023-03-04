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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    int n;
    int i;
    int ans = 0;

    cin >> n;
    vector<int> b(n), a(n);

    for (i = 0; i < n - 1; i++)
    {
        cin >> b[i];
    }

    a[0] = b[0];

    for (i = 1; i < n; i++)
    {
        a[i] = b[i - 1];

        a[i - 1] = min(a[i - 1], b[i - 1]);
    }

    for (i = 0; i < n; i++)
    {
        ans += a[i];
    }

    cout << ans << endl;
}