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

    vector<ll> f = {1, 1};

    for (int i = 2; i <= 90; i++)
    {
        f.push_back(f[i - 1] + f[i - 2]);
    }

    for (ll i = 0; i <= 90; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (n < f[i] + f[j])
            {
                break;
            }

            if (n - f[i] - f[j] - i < 130ll)
            {
                printf("%lld %lld\n", i, j);
            }
        }
    }
}