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
    int h, w, m;
    cin >> h >> w >> m;

    map<ll, ll> r, c;
    ll r_max = 0, c_max = 0;
    vector<int> a(m), b(m);

    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];

        r[a[i]]++;
        r_max = max(r_max, r[a[i]]);

        c[b[i]]++;
        c_max = max(c_max, c[b[i]]);
    }

    ll x = 0, y = 0;

    for (int i = 1; i <= h; i++)
    {
        if (r[i] == r_max)
        {
            x++;
        }
    }

    for (int i = 1; i <= w; i++)
    {
        if (c[i] == c_max)
        {
            y++;
        }
    }

    ll cnt = 0;

    bool flag = false;

    for (int i = 0; i < m; i++)
    {
        if (r[a[i]] == r_max && c[b[i]] == c_max)
        {
            cnt++;
        }
    }

    if (cnt == x * y)
    {
        cout << r_max + c_max - 1 << endl;
    }
    else
    {
        cout << r_max + c_max << endl;
    }
}
