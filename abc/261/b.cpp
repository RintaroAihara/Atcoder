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
    vector<vector<char>> a(n, vector<char>(n));
    bool flag = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[i][j] == '-' || a[i][j] == 'D')
            {
                if (a[i][j] != a[j][i])
                {
                    flag = false;
                }
            }
            else if (a[i][j] == 'W')
            {
                if (a[j][i] != 'L')
                {
                    flag = false;
                }
            }
            else if (a[i][j] == 'L')
            {
                if (a[j][i] != 'W')
                {
                    flag = false;
                }
            }
        }
    }

    if (flag)
    {
        cout << "correct" << endl;
    }
    else
    {
        cout << "incorrect" << endl;
    }
}