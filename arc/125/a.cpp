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
    ll n, m;
    cin >> n >> m;

    vector<ll> s(n), t(m);
    vector<ll> zero, one;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];

        if (s[i] == 1)
        {
            one.push_back(i);
        }
        else
        {
            zero.push_back(i);
        }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> t[i];
    }

    ll index = 0;

    ll ans = 0;

    for (int i = 0; i < m; i++)
    {
        if (t[i] == 1)
        {
            if (s[index] == t[i])
            {
                ans++;
            }
            else
            {
                
            }
            
        }
        else
        {
        }
    }
}