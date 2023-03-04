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

    vector<vector<int>> table(100001, vector<int>(4, 0));
    vector<int> sum(100002, 0);
    vector<P> p(n);

    for (int i = 0; i < n; i++)
    {
        int r, h;
        cin >> r >> h;

        p[i] = {r, h};
        table[r][h]++;
        table[r][0]++;
    }

    for (int i = 0; i < 100001; i++)
    {
        sum[i + 1] = sum[i] + table[i][0];
    }

    for (int i = 0; i < n; i++)
    {
        int w, l, t;
        w = l = t = 0;
        w += sum[p[i].first];
        l += sum[100001] - sum[p[i].first + 1];

        if (p[i].second == 1)
        {
            w += table[p[i].first][2];
            l += table[p[i].first][3];
            t += table[p[i].first][1] - 1;
        }
        else if (p[i].second == 2)
        {
            w += table[p[i].first][3];
            l += table[p[i].first][1];
            t += table[p[i].first][2] - 1;
        }
        else if (p[i].second == 3)
        {
            w += table[p[i].first][1];
            l += table[p[i].first][2];
            t += table[p[i].first][3] - 1;
        }

        printf("%d %d %d\n", w, l, t);
    }
}
