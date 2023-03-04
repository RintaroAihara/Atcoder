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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < q; i++)
    {
        ll k;
        cin >> k;

        ll l = -1, r = INF;

        while (r - l > 1)
        {
            ll mid = (r + l) / 2;

            auto x = lower_bound(a.begin(), a.end(), mid) - a.begin();

            x = mid - x;

            if (x > k)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }

        cout << l << endl;
    }
}