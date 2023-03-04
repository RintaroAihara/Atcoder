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
    ll n, q;
    cin >> n >> q;

    vector<vector<ll>> g(n, vector<ll>());

    for (int i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;

        a--, b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<ll> dis(n, INF);
    dis[0] = 0;

    queue<ll> que;
    que.push(0);

    while (que.size())
    {
        ll p = que.front();
        que.pop();

        for (auto &&i : g[p])
        {
            if (chmin(dis[i], dis[p] + 1))
            {
                que.push(i);
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        ll c, d;
        cin >> c >> d;
        c--, d--;

        if (abs(dis[c] - dis[d]) % 2 == 0)
        {
            cout << "Town" << endl;
        }
        else
        {
            cout << "Road" << endl;
        }
    }
}
