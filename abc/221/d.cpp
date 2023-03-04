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

    map<ll, ll> login;

    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;

        login[a]++;
        login[a + b]--;
    }

    map<ll, ll> ans;
    ll people = 0;
    ll day = 0;

    for (auto &&i : login)
    {
        ans[people] += i.first - day;
        people += i.second;
        day = i.first;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
}