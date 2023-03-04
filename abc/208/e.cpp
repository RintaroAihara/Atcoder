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

ll n, k;
vector<ll> N;
ll d;
ll ans;

ll calc(map<ll, ll> m)
{
    ll res = 1;
    ll y = 1;
    ll x = 1, z = 1;
    map<ll, ll> m;

    for (auto &&i : m)
    {
        ll y = 1;

        for (ll j = 1; j <= i.second; j++, z++)
        {
            y *= j;
            x *= z;
        }
    }

    res = x / y;

    return res;
}

void dfs(vector<ll> a)
{
    ll res = 0;

    map<ll, ll> m;
    for (ll i = 0; i < a.size(); i++)
    {
        m[a[i]]++;
    }

    if (a.size() < d)
    {
        res = calc(m);
    }
    else if (a.size() == d)
    {
        for (int i = 0; i < 10; i++)
        {
            if (N[d - 1] < i)
            {
                break;
            }
            else if (N[d - 1] > i)
            {
                auto m2 = m;

                if (m2[i] > 0)
                {
                    m2[i]--;
                }

                res += calc(m2);
            }
            else
            {        
            }
            
        }
    }
    else
    {
        return;
    }

    if (res == 0)
    {
        return;
    }

    ans += res;
}

int main(void)
{
    cin >> n >> k;
    ans = 0;

    ll x = n;
    d = 0;

    while (x)
    {
        N.push_back(x % 10ll);
        x /= 10ll;
        d++;
    }

    for (int i = 0; i < 10; i++)
    {
        dfs({i});
    }
}