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
    vector<double> x(4), y(4);

    for (int i = 0; i < 4; i++)
    {
        cin >> x[i] >> y[i];
    }

    double s = 0.0;

    for (int i = 0; i < 4; i++)
    {
        double a1 = x[i] - x[(i + 1) % 4], a2 = y[i] - y[(i + 1) % 4];
        double b1 = x[(i + 2) % 4] - x[(i + 1) % 4], b2 = y[(i + 2) % 4] - y[(i + 1) % 4];

        double c = (a1 * b1 + a2 * b2) / (sqrtl(a1 * a1 + a2 * a2) * sqrtl(b1 * b1 + b2 * b2));

        double theta = acosl(c);
        // cout << theta * 180.0 / M_PI << endl;

        s += theta * 180.0 / M_PI;

        if (theta * 180.0 / M_PI >= 180.0)
        {
            cout << "No" << endl;
            return 0;
        }
    }

    if (s < 360.0)
    {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
}