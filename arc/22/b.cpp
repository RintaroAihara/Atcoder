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
    vector<ll> is(1000000, 0);
    ll ans = 0;

    for (ll i = 0, j = 0; i < n; i++)
    {
        while (j < n && is[a[j]] == 0)
        {
            is[a[j]]++;
            j++;
        }

        chmax(ans, j - i);

        if (j == i)
        {
            j++;
        }
        else
        {
            is[a[i]]--;
        }
    }

    cout << ans << endl;
}