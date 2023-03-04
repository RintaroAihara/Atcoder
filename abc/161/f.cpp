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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

vector<ll> divisor(ll n)
{
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ret.push_back(i);
            if (i * i != n)
                ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}

int main(void)
{
    ll n;
    ll ans = 0;
    cin >> n;

    vector<ll> x, y;
    set<ll> p;

    x = divisor(n);
    y = divisor(n - 1);

    for (auto a : x)
    {
        p.insert(a);
    }

    for (auto b : y)
    {
        p.insert(b);
    }

    for (auto k : p)
    {
        ll n_ = n;

        if (k == 1)
        {
            continue;
        }

        while (n_ != 1)
        {
            if (n_ % k == 0)
            {
                n_ /= k;
            }
            else
            {
                n_ %= k;
            }

            if (n_ < k)
            {
                break;
            }
        }

        if (n_ == 1)
        {
            ans++;
        }
    }

    cout << ans << endl;
}