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

vector<vector<ll>> ans(2000, vector<ll>(2000, INF));
vector<vector<bool>> maze(2000, vector<bool>(2000, false));

int main(void)
{
    ll n, x, y;

    cin >> n >> x >> y;

    x += 1000;
    y += 1000;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        maze[a + 1000][b + 1000] = true;
    }

    if (maze[x + 1][y] && maze[x + 1][y - 1] && maze[x][y + 1] && maze[x + 1][y - 1] && maze[x - 1][y] && maze[x - 1][y - 1])
    {
        cout << -1 << endl;
        return 0;
    }

    if (maze[1001][1001] && maze[1000][1001] && maze[999][1001] && maze[1001][1000] && maze[999][1000] && maze[1000][999])
    {
        cout << -1 << endl;
        return 0;
    }

    ans[1000][1000] = 0;

    queue<P> q;
    q.push({1000, 1000});

    while (q.size())
    {
        P p = q.front();
        q.pop();

        if (p.first == x && p.second == y)
        {
            cout << ans[p.first][p.second] << endl;
            return 0;
        }

        int dx[6] = {1, 0, -1, 1, -1, 0};
        int dy[6] = {1, 1, 1, 0, 0, -1};

        for (int i = 0; i < 6; i++)
        {
            P next = {p.first + dx[i], p.second + dy[i]};

            if (!maze[next.first][next.second])
            {
                if (ans[next.first][next.second] > ans[p.first][p.second] + 1)
                {
                    ans[next.first][next.second] = ans[p.first][p.second] + 1;
                    q.push(next);
                }
            }
        }
    }
}
