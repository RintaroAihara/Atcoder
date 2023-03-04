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
    vector<ll> x(n);
    vector<ll> a(n + 1, 0);
    vector<vector<ll>> dp1(n + 10, vector<ll>(n + 10, 0)); //おもて
    vector<vector<ll>> dp2(n + 10, vector<ll>(n + 10, 0)); //うら

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    for (int i = 0; i < m; i++)
    {
        ll c, y;
        cin >> c >> y;
        a[c] = y;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            chmax(dp1[i + 1][j + 1], dp1[i][j] + a[j + 1] + x[i]);

            chmax(dp1[i + 1][1], dp2[i][0] + a[1] + x[i]);

            chmax(dp2[i + 1][0], dp1[i][j]);

            chmax(dp2[i + 1][0], dp2[i][0]);
        }
    }

    ll answer = 0;

    for (int i = 1; i <= n; i++)
    {
        chmax(answer, dp1[n][i]);
    }

    chmax(answer, dp2[n][0]);

    cout << answer << endl;
}