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

    set<int> genosis(int x)
    {
        set<int> g;

        while (x != 1)
        {
            g.insert(f[x]);
            x /= f[x];
        }

        return g;
    }

    // vector<P> genosiscount(int x)
    // {
    //     vector<P> gc;
    //     vector<int> g = genosis(x);

    //     if (g.empty() == 1)
    //     {
    //         return {};
    //     }

    //     gc.push_back(P(f[x], 0));

    //     for (auto &i : g)
    //     {
    //         if (gc.back().first == i)
    //         {
    //             gc.back().second++;
    //         }
    //         else
    //         {
    //             gc.push_back(P(i, 1));
    //         }
    //     }

    //     return gc;
    // }
};

int main(void)
{
    int n;
    cin >> n;

    eratosthenes e(1000010);

    map<ll, ll> m;

    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;

        for (auto &&i : e.genosis(a))
        {
            m[i]++;
        }
    }

    bool flag = true;

    for (auto &&i : m)
    {
        if (i.second == n)
        {
            cout << "not coprime" << endl;
            return 0;
        }

        if (i.second > 1)
        {
            flag = false;
        }
    }

    if (flag)
    {
        cout << "pairwise coprime" << endl;
    }
    else
    {
        cout << "setwise coprime" << endl;
    }
}
