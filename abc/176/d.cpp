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
    int h, w;

    cin >> h >> w;

    int ch, cw, dh, dw;
    cin >> ch >> cw >> dh >> dw;
    ch--;
    cw--;
    dh--;
    dw--;

    vector<vector<char>> maze(h, vector<char>(w));
    vector<vector<ll>> warp(h, vector<ll>(w, INF));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> maze[i][j];
        }
    }

    queue<P> q, visited;

    q.push({ch, cw});
    warp[ch][cw] = 0;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    while (q.size() || visited.size())
    {
        if (q.size())
        {
            P p = q.front();
            q.pop();

            int x = p.first, y = p.second;
            visited.push({x, y});

            for (int i = 0; i < 4; i++)
            {
                int next_x = x + dx[i], next_y = y + dy[i];

                if (next_x < 0 || next_y < 0 || next_x >= h || next_y >= w)
                {
                    continue;
                }

                if (maze[next_x][next_y] == '#')
                {
                    continue;
                }

                if (warp[x][y] < warp[next_x][next_y])
                {
                    warp[next_x][next_y] = warp[x][y];

                    q.push({next_x, next_y});
                }
            }
        }
        else
        {
            P p = visited.front();
            visited.pop();

            int x = p.first, y = p.second;

            for (int i = -2; i < 3; i++)
            {
                for (int j = -2; j < 3; j++)
                {
                    int next_x = x + i, next_y = y + j;

                    if (next_x < 0 || next_y < 0 || next_x >= h || next_y >= w)
                    {
                        continue;
                    }

                    if (maze[next_x][next_y] == '#')
                    {
                        continue;
                    }

                    if (warp[x][y] + 1 < warp[next_x][next_y])
                    {
                        warp[next_x][next_y] = warp[x][y] + 1;

                        q.push({next_x, next_y});
                    }
                }
            }
        }
    }

    if (warp[dh][dw] == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << warp[dh][dw] << endl;
    }
}
