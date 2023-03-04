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
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

int main(void)
{
    ll h, w;
    cin >> h >> w;

    vector<string> a(h);

    for (int i = 0; i < h; i++)
    {
        cin >> a[i];
    }

    map<char, vector<P>> teleporter;
    P s, g;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (a[i][j] == 'S')
            {
                s = {i, j};
            }
            else if (a[i][j] == 'G')
            {
                g = {i, j};
            }
            else if (islower(a[i][j]))
            {
                teleporter[a[i][j]].emplace_back(i, j);
            }
        }
    }

    vector<vector<ll>> d(h, vector<ll>(w, INF));
    queue<P> q;

    d[s.first][s.second] = 0;
    q.push(s);

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    while (q.size())
    {
        P p = q.front();
        q.pop();

        auto [x, y] = p;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= h || ny >= w || a[nx][ny] == '#')
            {
                continue;
            }

            if (chmin(d[nx][ny], d[x][y] + 1))
            {
                q.emplace(nx, ny);
            }
        }

        if (islower(a[x][y]))
        {
            for (auto &&i : teleporter[a[x][y]])
            {
                auto [nx, ny] = i;

                if (chmin(d[nx][ny], d[x][y] + 1))
                {
                    q.emplace(nx, ny);
                }
            }

            teleporter[a[x][y]].clear();
        }
    }

    if (d[g.first][g.second] == INF)
    {
        cout << -1 << endl;
        return 0;
    }

    cout << d[g.first][g.second] << endl;
}
