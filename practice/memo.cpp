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

vector<ll> fibonacci(1000, 0);

ll Fibonacci(ll x)
{
    if (x == 0)
    {
        return 0;
    }

    if (fibonacci[x])
    {
        return fibonacci[x];
    }

    // return fibonacci[x] = Fibonacci(x - 1) + Fibonacci(x - 2);
    return Fibonacci(x - 1) + Fibonacci(x - 2);
}

int main(void)
{
    ll x;
    cin >> x;

    fibonacci[1] = 1;

    cout << Fibonacci(x) << endl;
}
