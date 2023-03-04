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
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    auto d = divisor(sum);

    reverse(d.begin(), d.end());

    for (auto &&i : d)
    {
        vector<ll> mod(n);
        ll mod_sum = 0;
        for (int j = 0; j < n; j++)
        {
            mod[j] = a[j] % i;
            mod_sum += mod[j];
        }

        sort(mod.begin(), mod.end());

        ll tmp = 0;

        for (int j = 0; j < n - mod_sum / i; j++)
        {
            tmp += mod[j];
        }

        if (tmp <= k)
        {
            cout << i << endl;
            return 0;
        }
    }
}