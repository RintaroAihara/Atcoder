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
    ll n;
    ll x;
    cin >> n >> x;
    x *= 100;

    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        ll v, p;

        cin >> v >> p;

        sum += v * p;

        if (x < sum)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}
