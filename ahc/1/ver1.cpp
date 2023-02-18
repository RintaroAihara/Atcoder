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

class eratosthenes_sieve
{
private:
    int n;
    vector<int> f;

public:
    vector<int> primes;

    eratosthenes_sieve(int n) : f(n + 1)
    {
        f[0] = f[1] = -1;
        for (ll i = 2; i <= n; i++)
        {
            if (!f[i])
            {
                f[i] = i;
                primes.emplace_back(i);
                for (ll j = i * i; j <= n; j += i)
                {
                    if (!f[j])
                    {
                        f[j] = i;
                    }
                }
            }
        }
    }

    map<ll, ll> prime_factor(int x)
    {
        map<ll, ll> res;

        while (x != 1)
        {
            res[f[x]]++;
            x /= f[x];
        }

        return res;
    }
};

int main(void)
{
    ll n;

    eratosthenes_sieve e(100000000);
}