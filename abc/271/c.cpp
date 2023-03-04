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
    map<ll, bool> dict;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        dict[a[i]] = true;
    }

    sort(a.begin(), a.end());

    ll ans = 0;
    ll end = a.size();

    for (int i = 1; i <= a.size(); i++)
    {
        if (dict[i])
        {
            ans = i;
        }
        else
        {
            end -= 2;
            
        }
    }
}