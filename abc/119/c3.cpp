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

ll n, A, B, C;
ll ans = INF;
vector<ll> l(10);

void bfs(int a, int b, int c, int i, int m)
{
    if (i == n)
    {
        if (!a || !b || !c)
        {
            return;
        }

        ans = min(ans, abs(A - a) + abs(B - b) + abs(C - c) + m);

        return;
    }

    bfs(a + l[i], b, c, i + 1, a ? m + 10 : m);
    bfs(a, b + l[i], c, i + 1, b ? m + 10 : m);
    bfs(a, b, c + l[i], i + 1, c ? m + 10 : m);
    bfs(a, b, c, i + 1, m);
}

int main(void)
{
    cin >> n >> A >> B >> C;

    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }

    bfs(0, 0, 0, 0, 0);

    cout << ans << endl;
}
