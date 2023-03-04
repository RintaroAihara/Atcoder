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
    ll x, y;
    ll n;
    cin >> h >> w >> x >> y >> n;
    map<ll, set<ll>> r, c;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        r[a].insert(b);
        c[b].insert(a);
    }

    ll q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        char d;
        ll l;
        cin >> d >> l;

        if (d == 'R')
        {
            auto iter = r[x].lower_bound(y);
            if (iter == r[x].end())
            {
                if (y + l > w)
                {
                    y = w;
                }
                else
                {
                    y += l;
                }
            }
            else
            {
                if (y + l >= *iter)
                {
                    y = *iter - 1;
                }
                else if (y + l > w)
                {
                    y = w;
                }
                else
                {
                    y += l;
                }
            }
        }
        else if (d == 'L')
        {
            auto iter = r[x].lower_bound(y);
            if (r[x].size() == 0 || iter == r[x].begin())
            {
                if (y - l < 1)
                {
                    y = 1;
                }
                else
                {
                    y -= l;
                }
            }
            else
            {
                iter--;
                if (y - l <= *iter)
                {
                    y = *iter + 1;
                }
                else if (y - l < 1)
                {
                    y = 1;
                }
                else
                {
                    y -= l;
                }
            }
        }
        else if (d == 'D')
        {
            auto iter = c[y].lower_bound(x);
            if (iter == c[y].end())
            {
                if (x + l > h)
                {
                    x = h;
                }
                else
                {
                    x += l;
                }
            }
            else
            {
                if (x + l >= *iter)
                {
                    x = *iter - 1;
                }
                else if (x + l > h)
                {
                    x = h;
                }
                else
                {
                    x += l;
                }
            }
        }
        else if (d == 'U')
        {
            auto iter = c[y].lower_bound(x);
            if (c[y].size() == 0 || iter == c[y].begin())
            {
                if (x - l < 1)
                {
                    x = 1;
                }
                else
                {
                    x -= l;
                }
            }
            else
            {
                iter--;
                if (x - l <= *iter)
                {
                    x = *iter + 1;
                }
                else if (x - l < 1)
                {
                    x = 1;
                }
                else
                {
                    x -= l;
                }
            }
        }

        cout << x << " " << y << endl;
    }
}