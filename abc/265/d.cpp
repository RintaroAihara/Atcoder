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
    ll n, p, q, r;
    cin >> n >> p >> q >> r;

    vector<ll> a(n);
    vector<ll> s(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s[i + 1] = s[i] + a[i];
    }

    for (int i = 0; i < n; i++)
    {
        bool f = true;
        auto itr = lower_bound(s.begin(), s.end(), p + s[i]);
        if (itr == s.end() || *itr != p + s[i])
        {
            f = false;
        }

        ll y = itr - s.begin();
        itr = lower_bound(s.begin(), s.end(), q + s[y]);
        if (itr == s.end() || *itr != q + s[y])
        {
            f = false;
        }
        ll z = itr - s.begin();
        itr = lower_bound(s.begin(), s.end(), r + s[z]);
        if (itr == s.end() || *itr != r + s[z])
        {
            f = false;
        }
        if (f)
        {
            // cout << i << y << z << endl;
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}