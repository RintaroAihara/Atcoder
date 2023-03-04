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

    vector<vector<ll>> c(n, vector<ll>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c[i][j];
        }
    }

    vector<ll> a(n), b(n);

    for (int i = 0; i < n; i++)
    {
        ll tmp = INF;
        for (int j = 0; j < n; j++)
        {
            chmin(tmp, c[i][j]);
        }

        a[i] = tmp;
    }

    for (int i = 0; i < n; i++)
    {
        b[i] = c[0][i] - a[0];
        for (int j = 1; j < n; j++)
        {
            if (b[i] + a[j] != c[j][i])
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << endl;
    }
}