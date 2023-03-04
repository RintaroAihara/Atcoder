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
    ll h, w;
    cin >> h >> w;

    vector<string> m(h);

    for (int i = 0; i < h; i++)
    {
        cin >> m[i];
    }

    queue<P> q, q_;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (m[i][j] == '#')
            {
                q.push({i, j});
            }
        }
    }

    vector<vector<bool>> searched(h, vector<bool>(w, false));
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    ll ans = 0;

    while (q.size())
    {
        P p = q.front();
        q.pop();

        ll x = p.first, y = p.second;

        if (searched[x][y])
        {
            continue;
        }

        q_.push({x, y});

        ll black = 0, white = 0;

        while (q_.size())
        {
            P p_ = q_.front();
            q_.pop();

            ll x_ = p_.first, y_ = p_.second;

            if (searched[x_][y_])
            {
                continue;
            }

            if (m[x_][y_] == '#')
            {
                black++;
            }
            else
            {
                white++;
            }

            searched[x_][y_] = true;
            char c = m[x_][y_];

            for (int i = 0; i < 4; i++)
            {
                int nx = x_ + dx[i], ny = y_ + dy[i];

                if (nx < 0 || ny < 0 || nx >= h || ny >= w)
                {
                    continue;
                }

                if (m[nx][ny] == c)
                {
                    continue;
                }

                q_.push({nx, ny});
            }
        }

        ans += black * white;
    }

    cout << ans << endl;
}
