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
    ll n, q;
    string s;
    cin >> n >> s >> q;

    bool f = true;

    for (int i = 0; i < q; i++)
    {
        ll t, a, b;
        cin >> t >> a >> b;
        a--, b--;

        if (t == 1)
        {
            if (f)
            {
                swap(s[a], s[b]);
            }
            else
            {
                a = (a + n) % (2 * n);
                b = (b + n) % (2 * n);

                swap(s[a], s[b]);
            }
        }
        else
        {
            f = !f;
        }
    }

    if (f)
    {
        cout << s << endl;
    }
    else
    {
        for (int i = n; i < 2 * n; i++)
        {
            cout << s[i];
        }

        for (int i = 0; i < n; i++)
        {
            cout << s[i];
        }

        cout << endl;
    }
}