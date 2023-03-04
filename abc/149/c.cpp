#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = ll(1e18) + 1;

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

int main(void)
{
    ll x;
    eratosthenes e(200000);

    cin >> x;

    for (auto &z : e.primes)
    {
        if (z.first >= x)
        {
            cout << z.first << endl;
            break;
        }
    }
}