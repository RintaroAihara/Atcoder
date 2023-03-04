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
    int n, m, c;
    ll ans = 0;

    cin >> n >> m >> c;

    vector<int> b(m);
    int a[30][30];

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++)
    {
        ll point = 0;

        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];

            point += a[i][j] * b[j];
        }

        point += c;

        if (point > 0)
        {
            ans++;
        }
    }

    cout << ans << endl;
}