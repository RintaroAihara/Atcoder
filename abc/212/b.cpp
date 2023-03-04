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
    vector<ll> x(4);
    ll a;
    cin >> a;

    for (int i = 3; i >= 0; i--)
    {
        x[i] = a % 10;
        a /= 10;
    }

    bool f = false;

    for (int i = 1; i < 4; i++)
    {
        if (x[i] != x[0])
        {
            f = true;
        }
    }

    bool f1 = false;

    ll tmp = x[0];

    for (int i = 0; i < 3; i++)
    {
        if (x[(i + 1) % 4] != (x[i] + 1) % 10)
        {
            f1 = true;
        }
    }

    if (f & f1)
    {
        cout << "Strong" << endl;
    }
    else
    {
        cout << "Weak" << endl;
    }
}