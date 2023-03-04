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
    string s;
    cin >> n >> s;

    vector<int> a(n + 1, 0), t(n + 1, 0), c(n + 1, 0), g(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        a[i + 1] = a[i];
        t[i + 1] = t[i];
        c[i + 1] = c[i];
        g[i + 1] = g[i];
        if (s[i] == 'A')
        {
            a[i + 1] += 1;
        }
        else if (s[i] == 'T')
        {
            t[i + 1] += 1;
        }
        else if (s[i] == 'C')
        {

            c[i + 1] += 1;
        }
        else
        {

            g[i + 1] += 1;
        }
    }

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[j] - a[i] == t[j] - t[i] &&c[j] - c[i] == g[j] - g[i])
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
}
