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
    vector<string> s(n);
    map<string, ll> m;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        m[s[i]]++;

        if (m[s[i]] == 1)
        {
            cout << s[i] << endl;
        }
        else
        {
            ll x = m[s[i]] - 1;
            s[i].push_back('(');
            s[i] += to_string(x);
            s[i].push_back(')');

            cout << s[i] << endl;
        }
    }
}