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

class Position
{
public:
    ll x, y;
    Position(ll _x, ll _y)
    {
        x = _x;
        y = _y;
    }
};

class Optimizer
{
private:
    double sigma;
    double D = 1e6;
    double R = 1e9;
    // random_device seed_gen;
    // default_random_engine engine(seed_gen());

    // uniform_int_distribution<> dist(-1e9, 1e9);

public:
    Optimizer(double s)
    {
        sigma = s;
    };

    Position predict(double theta, Position pos)
    {
        Position res = pos;

        res.x += ll(2.0 * D * cos(theta));
        res.y += ll(2.0 * D * sin(theta));

        return res;
    }

    Position random_predict()
    {
        Position res(0ll, 0ll);

        return res;
    }
};

int main(void)
{
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();

    double sigma;
    cin >> sigma;

    Optimizer opt(sigma);
    Position p(0ll, 0ll);

    cout << p.x << " " << p.y << endl;

    while (true)
    {
        int r;
        cin >> r;
        if (r == 2)
        {
            ll x, y;
            cin >> x >> y;
            return 0;
        }
        else if (r == 1)
        {
            ll x, y;
            cin >> x >> y;
            p = opt.random_predict();
            cout << p.x << " " << p.y << endl;
        }
        else if (r == 0)
        {
            double theta;
            cin >> theta;
            p = opt.predict(theta, p);
            cout << p.x << " " << p.y << endl;
        }

        end = chrono::system_clock::now();
        if (chrono::duration_cast<chrono::milliseconds>(end - start).count() >= 1950.0)
        {
            return 0;
        }
    }
}