#include <bits/stdc++.h>

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

    vector<vector<ll>> a(h, vector<ll>(w, 0));
    vector<vector<char>> g(h, vector<char>(w));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> g[i][j];
        }
    }

    ll x = 0, y = 0;

    while (true)
    {
        if (a[x][y])
        {
            cout << -1 << endl;
            return 0;
        }

        a[x][y] = 1;

        ll nx = x, ny = y;

        if (g[x][y] == 'R')
        {
            ny += 1;
        }
        else if (g[x][y] == 'L')
        {
            ny -= 1;
        }
        else if (g[x][y] == 'U')
        {
            nx -= 1;
        }
        else if (g[x][y] == 'D')
        {
            nx += 1;
        }

        if (nx >= h || ny >= w || nx < 0 || ny < 0)
        {
            cout << x + 1 << endl
                 << y + 1 << endl;

            return 0;
        }

        x = nx, y = ny;
    }
}