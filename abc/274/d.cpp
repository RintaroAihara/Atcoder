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
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    map<ll, ll> mx, my;

    mx[a[0]] = 1;
    my[0] = 1;

    for (int i = 2; i < n; i += 2)
    {
        set<ll> s;
        for (auto &&j : mx)
        {
            s.insert(j.first + a[i]);
            s.insert(j.first - a[i]);
        }
        mx.clear();

        for (auto &&j : s)
        {
            mx[j] = 1;
        }
    }

    for (int i = 1; i < n; i += 2)
    {
        set<ll> s;
        for (auto &&j : my)
        {
            s.insert(j.first + a[i]);
            s.insert(j.first - a[i]);
        }
        my.clear();

        for (auto &&j : s)
        {
            my[j] = 1;
        }
    }

    if (mx[x] && my[y])
    {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
}