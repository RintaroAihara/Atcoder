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

    map<ll, pair<ll, ll>> ma;
    vector<map<ll, ll>> v(n);

    for (int i = 0; i < n; i++)
    {
        ll m;
        cin >> m;

        for (int j = 0; j < m; j++)
        {
            ll p, e;
            cin >> p >> e;
            v[i][p] = e;

            if (ma[p].first == e)
            {
                ma[p].second++;
            }
            else if (ma[p].first < e)
            {
                ma[p].first = e;
                ma[p].second = 1;
            }
        }
    }

    set<set<ll>> ans;

    for (int i = 0; i < n; i++)
    {
        set<ll> s;
        for (auto &&j : v[i])
        {
            if (ma[j.first].second == 1 && ma[j.first].first == j.second)
            {
                s.insert(j.first);
            }
        }
        ans.insert(s);
    }

    ll res = 0;

    for (auto &&i : ans)
    {
        for (auto &&j : i)
        {
            // cout << j << endl;
        }
        // cout << endl;
        res++;
    }

    cout << res << endl;
}