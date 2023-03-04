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
    ll h1, w1;
    cin >> h1 >> w1;
    vector<vector<ll>> a(h1, vector<ll>(w1, 0));

    for (int i = 0; i < h1; i++)
    {
        for (int j = 0; j < w1; j++)
        {
            cin >> a[i][j];
        }
    }

    ll h2, w2;
    cin >> h2 >> w2;
    vector<vector<ll>> b(h2, vector<ll>(w2, 0));

    for (int i = 0; i < h2; i++)
    {
        for (int j = 0; j < w2; j++)
        {
            cin >> b[i][j];
        }
    }

    ll ans = 0;

    for (ll i = 0; i < (1ll << h1); i++)
    {
        auto cnt = 0;
        for (ll j = 0; j < 10; j++)
        {
            if ((i >> j) & 1ll)
            {
                cnt++;
            }
        }

        if (cnt != h2)
        {
            continue;
        }

        for (ll j = 0; j < (1ll << w1); j++)
        {
            bool flag = true;
            auto cnt = 0;
            for (ll k = 0; k < 10; k++)
            {
                if ((j >> k) & 1ll)
                {
                    cnt++;
                }
            }

            if (cnt != w2)
            {
                continue;
            }

            ll x = 0;

            for (ll k = 0; k < h1; k++)
            {
                if ((i >> k) & 1)
                {
                }
                else
                {
                    x++;
                    continue;
                }

                ll y = 0;

                for (ll l = 0; l < w1; l++)
                {
                    if ((j >> l) & 1)
                    {
                    }
                    else
                    {
                        y++;
                        continue;
                    }

                    if (a[k][l] != b[k - x][l - y])
                    {
                        flag = false;
                    }
                }
            }

            if (flag)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}