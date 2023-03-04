#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <tuple>
#include <numeric>
#include <cassert>
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
    vector<ll> a(n);

    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(210, vector<ll>()));

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<ll> b, c;

    bool flag = false;

    for (int i = 0; i < n; i++)
    {
        for (ll j = 0; j < 200; j++)
        {
            ll x = ((j - a[i]) % 200 + 200) % 200;

            if (dp[i][x].size() && dp[i][j].size())
            {
                b = dp[i][x];
                b.push_back(i + 1);
                c = dp[i][j];
                flag = true;
                break;
            }
            else if (dp[i][x].size() && dp[i][j].empty())
            {
                dp[i + 1][j] = dp[i][x];
                dp[i + 1][j].push_back(i + 1);
            }
            else
            {
                dp[i + 1][j] = dp[i][j];
            }
        }

        if (flag)
        {
            break;
        }

        if (dp[i + 1][a[i] % 200].size())
        {
            b = dp[i + 1][a[i] % 200];
            c.push_back(i + 1);
            flag = true;
        }
        else
        {
            dp[i + 1][a[i] % 200].push_back(i + 1);
        }

        if (flag)
        {
            break;
        }
    }

    if (flag)
    {
        cout << "Yes" << endl;
        cout << b.size() << " ";
        for (auto &&i : b)
        {
            cout << i << " ";
        }

        cout << endl;
        cout << c.size() << " ";
        for (auto &&i : c)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
