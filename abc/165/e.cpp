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

int main(void)
{
    ll n, m;

    cin >> n >> m;

    set<ll> s;

    ll a = 1, b = n;

    for (ll i = 0; i < m; i++)
    {
        if (s.find(abs(b - a)) != s.end() || s.find(abs(n + a - b)) != s.end() || abs(b - a) == abs(n + a - b))
        {
            b--;
        }

        cout << a << " " << b << endl;
        s.insert(abs(b - a));
        s.insert(abs(n + a - b));

        a++;
        b--;
    }
}
