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
    int n, m, Q;
    cin >> n >> m >> Q;

    vector<vector<int>> v(n, vector<int>(n, 0)), sum(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        v[l][r] += 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum[i + 1][j + 1] = v[i][j] + sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
        }
    }

    for (int i = 0; i < Q; i++)
    {
        int p, q;
        cin >> p >> q;
        int ans = 0;
        p--;

        ans = sum[q][q] + sum[p][p] - sum[p][q] - sum[q][p];

        cout << ans << endl;
    }
}
