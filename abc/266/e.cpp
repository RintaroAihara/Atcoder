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

    vector<double> x(1000, 0.0);
    x[1] = 3.5;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (double(j) < x[i - 1])
            {
                x[i] += x[i - 1];
            }
            else
            {
                x[i] += double(j);
            }
        }

        x[i] /= 6.0;
    }

    printf("%.8f\n", x[n]);
}