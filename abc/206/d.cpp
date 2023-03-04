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

    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<ll> p, q;
    vector<set<ll>> num(200100, set<ll>());
    for (int i = 0; i < n / 2; i++)
    {
        p.push_back(a[i]);
        num[a[i]].insert(i);
    }

    for (int i = 0; i < n / 2; i++)
    {
        q.push_back(a[n - i - 1]);
    }

    ll ans = n / 2;

    for (int i = 0; i < n / 2; i++)
    {
        ll s = p[i];

        while (true)
        {
            ll next = q[i];
        }
    }

    cout << max(ans - 1, 0ll) << endl;
}