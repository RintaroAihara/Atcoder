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
    ll n, k;
    cin >> n >> k;

    vector<ll> c(n);
    map<ll, ll> m;

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    ll ans = 0;

    set<ll> s;

    for (int i = 0; i < k; i++)
    {
        s.insert(c[i]);
        m[c[i]]++;
    }

    ans = s.size();
    ll tmp = ans;

    for (int i = k; i < n; i++)
    {
        m[c[i - k]]--;
        m[c[i]]++;

        if (c[i - k] == c[i])
        {
        }
        else if (m[c[i - k]] > 0 && m[c[i]] == 1)
        {
            tmp++;
        }
        else if (m[c[i - k]] == 0 && m[c[i]] > 1)
        {
            tmp--;
        }

        // cout << tmp << endl;

        chmax(ans, tmp);
    }

    cout << ans << endl;
}