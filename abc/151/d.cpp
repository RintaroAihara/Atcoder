#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
#include <stack>
#define rep(i, s, g) for (i = s; i <= g; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1e9 + 7;

int H, W;

int d[20][20];

char map[20][20];

int bfs(P s, P g)
{
    queue<P> q;
    P dx[4] = {P(1, 0), P(0, 1), P(-1, 0), P(0, -1)};
    int i, j;

    rep(i, 0, H - 1)
    {
        rep(j, 0, W - 1)
        {
            d[i][j] = MOD;
        }
    }

    d[s.first][s.second] = 0;
    q.push(s);

    while (q.size())
    {
        P p = q.front();
        q.pop();

        if (p == g)
        {
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = p.first + dx[i].first;
            int ny = p.second + dx[i].second;

            if (nx < H && ny < W && nx >= 0 && ny >= 0 && map[nx][ny] == '.' && d[nx][ny] == MOD)
            {
                q.push(P(nx, ny));

                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }

    return d[g.first][g.second];
}

int main(void)
{
    int ans = 0;
    int i, j, k, l;

    cin >> H >> W;

    rep(i, 0, H - 1)
    {
        rep(j, 0, W - 1)
        {
            cin >> map[i][j];
        }
    }

    rep(i, 0, H - 1)
    {
        rep(j, 0, W - 1)
        {
            rep(k, 0, H - 1)
            {
                rep(l, 0, W - 1)
                {
                    if (map[i][j] == '.' && map[k][l] == '.')
                    {
                        ans = max(bfs(P(i, j), P(k, l)), ans);
                    }
                }
            }
        }
    }

    cout << ans << endl;
}