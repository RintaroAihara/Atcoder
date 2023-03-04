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

int two(int a)
{
    int ans = 0;

    while (a % 2 == 0)
    {
        ans++;
        a /= 2;
    }

    return ans;
}

int main(void)
{
    int N, M;
    int a;
    int i, j;
    ll l = 1;
    int ans = 0;
    int flag;
    eratosthenes e(1e8);

    cin >> N >> M;

    rep(i, 0, N - 1)
    {
        cin >> a;
        a /= 2;
        if (i == 0)
        {
            flag = two(a);
        }

        if (flag != two(a) && i != 0)
        {
            cout << 0 << endl;
            return 0;
        }

        for (auto &x : e.genosiscount(a))
        {
            for (auto &y : e.primes)
            {
                if (x.first == y.first && x.second > y.second)
                {
                    y.second = x.second;
                }

                if (x.first < y.first)
                {
                    break;
                }
            }
        }
    }

    for (auto &x : e.primes)
    {
        rep(i, 1, x.second)
        {
            l *= x.first;
        }
    }

    cout << (M / l + 1) / 2 << endl;
}