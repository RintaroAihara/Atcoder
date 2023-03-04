#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
#include <stack>
#define rep(i, s, g) for (i = s; i <= g; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1e9 + 7;

struct eratosthenes
{
    int n;
    vector<int> f;
    vector<P> primes;

    eratosthenes(int n) : f(n + 1)
    {
        ll i, j;
        f[0] = f[1] = -1;
        for (i = 2; i <= n; i++)
        {
            if (!f[i])
            {
                f[i] = i;
                primes.push_back(P(i, 0));
                for (j = i * i; j <= n; j += i)
                {
                    if (!f[j])
                    {
                        f[j] = i;
                    }
                }
            }
        }
    }

    vector<int> genosis(int x)
    {
        vector<int> g;

        while (x != 1)
        {
            g.push_back(f[x]);
            x /= f[x];
        }

        return g;
    }

    vector<P> genosiscount(int x)
    {
        vector<P> gc;
        vector<int> g = genosis(x);

        if (g.empty() == 1)
        {
            return {};
        }

        gc.push_back(P(f[x], 0));

        for (auto &i : g)
        {
            if (gc.back().first == i)
            {
                gc.back().second++;
            }
            else
            {
                gc.push_back(P(i, 1));
            }
        }

        return gc;
    }
};

ll power(ll x, ll y)
{
    ll ans = 1;
    while (y)
    {
        if (y & 1)
            ans = (ans * x) % 1000000007;
        x = (x * x) % 1000000007;
        y >>= 1;
    }
    return ans;
}

int main(void)
{
    eratosthenes a(1e6 + 1);
    int N;
    int A[10010];
    int i, j;
    ll ans = 0;
    ll lcm = 1;

    cin >> N;

    for (i = 0; i < N; i++)
    {
        cin >> A[i];

        for (auto &j : a.genosiscount(A[i]))
        {
            for (auto &k : a.primes)
            {
                if (j.first == k.first && j.second > k.second)
                {
                    k.second = j.second;
                }

                if (j.first < k.first)
                {
                    break;
                }
            }
        }
    }

    for (auto &x : a.primes)
    {
        lcm = lcm * power(x.first, x.second) % 1000000007;
    }

    for (i = 0; i < N; i++)
    {
        ll add = lcm * power(A[i], 1000000005) % 1000000007;
        ans = (ans + add) % 1000000007;
    }

    cout << ans << endl;
}