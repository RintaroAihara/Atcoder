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
    priority_queue<P, vector<P>, greater<P>> q;

    for (int i = 0; i < m; i++)
    {
        ll a, c;
        cin >> a >> c;
        q.push({c, a});
    }

    ll ans = 0;

    ll e = 0;

    set<ll> s;

    while (q.size())
    {
        P p = q.top();
        q.pop();

        if (s.size() == 0)
        {
            ll g = gcd(n, p.second);

            e = n - g;
            ans = e * p.first;

            s.insert(g);
        }
        else
        {
            if (s.find(gcd(n, p.second)) != s.end())
            {
                continue;
            }
            else
            {
                ans += ((n - 1) - e) * p.first;
                e = n - 1;
            }
        }

        if (e == n - 1)
        {
            cout << ans << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}