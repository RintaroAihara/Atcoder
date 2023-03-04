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
    vector<ll> c(n);
    vector<ll> x(n);
    vector<ll> cnt(n + 1, 0);
    vector<ll> th(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    auto x2 = x;
    sort(x2.begin(), x2.end());

    ll cost = 0;

    for (int i = 0; i < n; i++)
    {
        ll y = th[x[i]];
        th[x[i]]++;

        auto it = lower_bound(x2.begin(), x2.end(), x[i]);

        ll idx = it - x2.begin() + y;
        if (i - idx > 0)
        {
            cost += i - idx;
            cost -= cnt[c[i]];
        }
        else
        {
            cost -= i - idx;
            auto it2 = lower_bound(x2.begin(), x2.end(), x2[i] + 1);
            ll d = it2 - x2.begin();
            cost -= d - i;
        }

        cout << cost << endl;

        cnt[c[i]]++;
    }

    cout << cost << endl;
}