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
    double a, b, d;
    cin >> a >> b >> d;
    double r = M_PI / 180.0 * d;
    printf("%.7lf\n", a * cos(r) - b * sin(r));
    printf("%.7lf\n", a * sin(r) + b * cos(r));
}