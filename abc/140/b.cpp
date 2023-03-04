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
    int x, y, z;
    int ans = 0;

    cin >> n;

    vector<int> a(n), b(n), c(n);

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (i = 0; i < n - 1; i++)
    {
        cin >> c[i];
    }

    for (i = 0; i < n; i++)
    {
        ans += b[a[i] - 1];

        if (a[i] + 1 == a[i + 1])
        {
            ans += c[a[i] - 1];
        }
    }

    cout << ans << endl;
}