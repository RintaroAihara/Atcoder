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
    ll n;
    cin >> n;

    map<int, char> dict;

    for (int i = 0; i < 10; i++)
    {
        dict[i] = char('0' + i);
    }

    for (int i = 0; i < 6; i++)
    {
        dict[10 + i] = char('A' + i);
    }

    cout << dict[n / 16] << dict[n % 16] << endl;
}