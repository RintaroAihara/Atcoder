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
    ll q;
    cin >> q;

    ll s = 0;

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for (int i = 0; i < q; i++)
    {
        ll t, x;
        cin >> t;

        if (t == 1)
        {
            cin >> x;
            pq.push(x - s);
        }
        else if (t == 2)
        {
            cin >> x;
            s += x;
        }
        else if (t == 3)
        {
            ll ans = pq.top();
            pq.pop();

            cout << ans + s << endl;
        }
    }
}