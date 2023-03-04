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

    vector<ll> t(n), l(n), r(n);

    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> l[i] >> r[i];
    }

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (r[i] > r[j])
            {
                if (r[j] > l[i])
                {
                    ans++;
                }
                else if (r[j] == l[i])
                {
                    if ((t[j] == 1 || t[j] == 3) && (t[i] == 1 || t[i] == 2))
                    {
                        ans++;
                    }
                }
            }
            else
            {
                if (r[i] > l[j])
                {
                    ans++;
                }
                else if (r[i] == l[j])
                {
                    if ((t[i] == 1 || t[i] == 3) && (t[j] == 1 || t[j] == 2))
                    {
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans << endl;
}