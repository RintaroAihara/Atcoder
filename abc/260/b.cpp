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
    ll n, x, y, z;
    cin >> n >> x >> y >> z;

    vector<P> ab(n);
    vector<P> a(n), b(n), c(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = -i;
        c[i].first = a[i].first;
        c[i].second = -i;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i].first;
        b[i].second = -i;
        c[i].first += b[i].first;
    }

    sort(a.begin(), a.end(), greater<P>());
    sort(b.begin(), b.end(), greater<P>());
    sort(c.begin(), c.end(), greater<P>());

    set<ll> ans;
    ll i = 0;
    ll cnt = 0;

    while (true)
    {
        if (cnt >= x)
        {
            break;
        }
        if (ans.find(-a[i].second) == ans.end())
        {
            ans.insert(-a[i].second);
            cnt++;
        }
        i++;
    }

    i = 0;
    cnt = 0;

    while (true)
    {
        if (cnt >= y)
        {
            break;
        }
        if (ans.find(-b[i].second) == ans.end())
        {
            ans.insert(-b[i].second);
            cnt++;
        }
        i++;
    }

    i = 0;
    cnt = 0;

    while (true)
    {
        if (cnt >= z)
        {
            break;
        }
        if (ans.find(-c[i].second) == ans.end())
        {
            ans.insert(-c[i].second);
            cnt++;
        }
        i++;
    }

    for (auto &&i : ans)
    {
        cout << i + 1 << endl;
    }
}