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

    vector<queue<ll>> a(m, queue<ll>());
    vector<ll> num(n, 0);
    vector<vector<ll>> locate(n, vector<ll>());
    queue<ll> q;
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;

        for (int j = 0; j < k; j++)
        {
            ll x;
            cin >> x;
            x--;
            a[i].push(x);
            locate[x].push_back(i);

            if (j == 0)
            {
                num[x]++;

                if (num[x] == 2)
                {
                    q.push(x);
                }
            }
        }
    }

    set<ll> end_num;

    while (q.size())
    {
        ll x = q.front();
        q.pop();

        for (int i = 0; i < 2; i++)
        {
            a[locate[x][i]].pop();

            if (a[locate[x][i]].size())
            {
                ll next_x = a[locate[x][i]].front();

                num[next_x]++;

                if (num[next_x] == 2)
                {
                    q.push(next_x);
                }
            }
        }

        end_num.insert(x);
    }

    if (end_num.size() == n)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}