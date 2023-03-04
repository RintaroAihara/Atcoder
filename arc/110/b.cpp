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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    ll n;
    string s;
    cin >> n >> s;

    if (s == "0")
    {
        cout << 10000000000 << endl;
        return 0;
    }
    if (s == "1")
    {
        cout << 20000000000 << endl;
        return 0;
    }
    if (s == "11")
    {
        cout << 10000000000 << endl;
        return 0;
    }
    if (s == "10")
    {
        cout << 10000000000 << endl;
        return 0;
    }

    if (s == "01")
    {
        cout << 9999999999 << endl;
        return 0;
    }

    ll l = 0;

    string x = "";

    for (int i = 0; i < n / 3 + 2; i++)
    {
        x += "110";
    }

    bool flag = false;

    ll a = 0;

    for (int i = 0; i < 3; i++)
    {
        bool f = true;

        for (int j = 0; j < n; j++)
        {
            if (x[j + i] != s[j])
            {
                f = false;
                break;
            }
        }

        if (f)
        {
            flag = true;
            a = i;
            break;
        }
    }

    if (a == 0)
    {
        if (n % 3 == 0)
        {
            l = n / 3;
        }
        else
        {
            l = n / 3 + 1;
        }
    }
    else if (a == 1)
    {
        if ((n - 2) % 3 == 0)
        {
            l = (n - 2) / 3 + 1;
        }
        else
        {
            l = (n - 2) / 3 + 2;
        }
    }
    else if (a == 2)
    {
        if ((n - 1) % 3 == 0)
        {
            l = (n - 1) / 3 + 1;
        }
        else
        {
            l = (n - 1) / 3 + 2;
        }
    }

    if (flag)
    {
        cout << (10000000000ll - l + 1) << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}
