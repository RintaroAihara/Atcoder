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

map<int64_t, int> prime_factor(int64_t n)
{
    map<int64_t, int> ret;
    for (int64_t i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1)
        ret[n] = 1;
    return ret;
}

int main(void)
{
    ll n;
    cin >> n;

    vector<ll> v(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        auto p = prime_factor(i);
        
        for (auto x : p)
        {
            v[x.first] += x.second;
        }
    }

    ll ans = 0;

    for (int i = 0; i <= n; i++)
    {
        if (v[i] >= 74)
        {
            ans++;
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == j)
            {
                continue;
            }

            if (v[i] >= 2 && v[j] >= 24)
            {
                ans++;
            }

            if (v[i] >= 4 && v[j] >= 14)
            {
                ans++;
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                if (i == k || j == k)
                {
                    continue;
                }

                if (v[i] >= 4 && v[j] >= 4 && v[k] >= 2)
                {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}
