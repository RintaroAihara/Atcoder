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
    ll r, c;
    cin >> r >> c;

    r = abs(8 - r);
    c = abs(8 - c);

    ll m = max(r, c);

    if (m % 2 == 0)
    {
        cout << "white" << endl;
    }
    else
    {
        cout << "black" << endl;
    }
}