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

int main(void)
{
    string x;
    ll m;
    cin >> x >> m;

    if (x.size() == 1)
    {
        if (x[0] - '0' > m)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << 1 << endl;
        }

        return 0;
    }

    ll d = 0;

    for (int i = 0; i < x.size(); i++)
    {
        d = max(d, ll(x[i] - '0'));
    }

    ll l = d, r = INF;

    while (r - l > 1)
    {
        ll mid = (l + r) / 2;

        ll res = *x.rbegin() - '0';
        ll n = 1;
        bool flag = true;

        for (ll j = x.size() - 2; j >= 0; j--)
        {
            if (n > m / mid)
            {
                flag = false;
                break;
            }

            n *= mid;

            res += (x[j] - '0') * n;
        }

        if (flag)
        {
            if (res > m)
            {
                flag = false;
            }
        }

        if (flag)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    cout << l - d << endl;
}