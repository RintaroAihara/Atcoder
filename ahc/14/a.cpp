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

class Rectjoin
{
private:
    ll n, m;
    ll c;
    ll s = 0;
    vector<ll> x, y;
    vector<vector<bool>> g;

public:
    Rectjoin(ll _n, ll _m, vector<ll> _x, vector<ll> _y)
    {
        n = _n;
        m = _m;
        c = (n - 1) / 2;
        x = _x;
        y = _y;
        s = calc_s();
        g.assign(n, vector<bool>(n, false));
        for (int i = 0; i < x.size(); i++)
        {
            g[x[i]][y[i]] = true;
        }
    }

    ll calc_s()
    {
        ll res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res += (i - c) * (i - c) + (j - c) * (j - c) + 1;
            }
        }
        // cout << res << endl;
        // cout << n * n * (((n + 1) * (2 * n + 1 - 6 * c) + 6 * c * c) / 3 + 1) << endl;

        // return n * n * (((n + 1) * (2 * n + 1 - 6 * c) + 6 * c * c) / 3 + 1);
        return res;
    }

    ll calc_score()
    {
        ll sum = 0;
        for (int i = 0; i < x.size(); i++)
        {
            sum += (x[i] - c) * (x[i] - c) + (y[i] - c) * (y[i] - c) + 1;
        }

        return round((1e6 * n * n * sum) / (m * s));
    }

    ll search(ll score)
    {
        vector<ll> l(3);
        ll _x, _y;
        ll bestscore = score;
        for (int i = 0; i < x.size(); i++)
        {
            for (int j = i + 1; j < x.size(); j++)
            {
                for (int k = j + 1; k < x.size(); k++)
                {
                    l[0] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                    l[1] = (x[j] - x[k]) * (x[j] - x[k]) + (y[j] - y[k]) * (y[j] - y[k]);
                    l[2] = (x[i] - x[k]) * (x[i] - x[k]) + (y[i] - y[k]) * (y[i] - y[k]);

                    ll index = max_element(l.begin(), l.end()) - l.begin();

                    ll nx, ny;
                    if (index == 0)
                    {
                        nx = x[i] + (x[j] - x[k]);
                        ny = y[i] + (y[j] - y[k]);
                    }
                    else if (index == 1)
                    {
                        nx = x[k] + (x[j] - x[i]);
                        ny = y[k] + (y[j] - y[i]);
                    }
                    else if (index == 2)
                    {
                        nx = x[i] + (x[k] - x[j]);
                        ny = y[i] + (y[k] - y[j]);
                    }

                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    {
                        continue;
                    }

                    if (g[nx][ny])
                    {
                        continue;
                    }

                    auto _x = x;
                    auto _y = y;
                    x.push_back(nx);
                    y.push_back(ny);

                    if (bestscore < calc_score())
                    {
                        
                    }
                    x = _x;
                    y = _y;
                }
            }
        }
    }
};

int main(void)
{
    ll n, m;
    cin >> n >> m;
    vector<ll> x(m), y(m);

    for (int i = 0; i < m; i++)
    {
        cin >> x[i] >> y[i];
    }

    auto rectjoin = Rectjoin(n, m, x, y);

    cout << rectjoin.calc_score() << endl;
}