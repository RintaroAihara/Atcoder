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
    vector<ll> r(h), c(w);
    for (int i = 0; i < h; i++)
    {
        cin >> r[i];
    }

    for (int i = 0; i < w; i++)
    {
        cin >> c[i];
    }

    vector<vector<ll>> a(h, vector<ll>(w, 0));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<ll> cr(h), cc(w, 0);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            
        }
    }
}