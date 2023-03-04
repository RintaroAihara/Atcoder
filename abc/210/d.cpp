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
    ll h, w, c;
    cin >> h >> w >> c;

    vector<vector<ll>> a(h, vector<ll>(w));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<ll> d(h + w - 1, INF), e(h + w - 1, INF);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            chmin(d[i + j], a[i][j]);
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            chmin(e[i - j + min(h, w)], a[i][j]);
        }
    }

    for (int i = 0; i < h + w - 1; i++)
    {
        cout << e[i] << endl;
    }

    ll ans = INF;

    for (int i = 0; i < h + w - 1; i++)
    {
        for (int j = i + 1; j < h + w - 1; j++)
        {
            // chmin(ans, c * (j - i) + d[i] + d[j]);
            cout << c * (j - i) + e[i] + e[j] << endl;
            chmin(ans, c * (j - i) + e[i] + e[j]);
        }
    }

    cout << ans << endl;
}