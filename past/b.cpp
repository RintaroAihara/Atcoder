#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
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
    int n, m, q;
    cin >> n >> m >> q;

    vector<ll> solved(m, 0), p[n];

    for (int i = 0; i < q; i++)
    {
        int s;
        cin >> s;

        if (s == 1)
        {
            int a;
            cin >> a;
            ll ans = 0;

            for (auto x : p[a - 1])
            {
                ans += n - solved[x - 1];
            }

            cout << ans << endl;
        }
        else
        {
            int a, b;

            cin >> a >> b;

            p[a - 1].push_back(b);
            solved[b - 1]++;
        }
    }
}
