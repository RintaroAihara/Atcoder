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
    vector<long double> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long double l = 0.0, r = 100000000000000.0;

    while (r - l > 1e-7)
    {
        long double c1 = (l * 2.0 + r) / 3.0;
        long double c2 = (l + r * 2.0) / 3.0;

        long double e1 = 0, e2 = 0;

        for (int i = 0; i < n; i++)
        {
            e1 += c1 + a[i] - min(a[i], c1 * (long double)2);
            e2 += c2 + a[i] - min(a[i], c2 * (long double)2);
        }

        if (e1 > e2)
        {
            l = c1;
        }
        else
        {
            r = c2;
        }
    }

    long double ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += r + a[i] - min(a[i], r * double(2));
    }

    ans /= (long double)n;

    printf("%.8Lf\n", ans);
}