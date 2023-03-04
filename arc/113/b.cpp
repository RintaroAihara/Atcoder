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

ll power(ll x, ll y, ll m)
{
    ll ans = 1;
    while (y)
    {
        if (y & 1)
            ans = (ans * x) % m;
        x = (x * x) % m;
        y >>= 1;
    }
    return ans;
}

int main(void)
{
    ll a, b, c;
    cin >> a >> b >> c;

    vector<ll> m;
    ll tmp = a % 10;
    m.push_back(tmp);

    for (int i = 0; i < 100; i++)
    {
        tmp *= a;
        tmp %= 10;

        if (tmp == a % 10)
        {
            break;
        }

        m.push_back(tmp);
    }

    cout << m[(power(b, c, m.size()) - 1 + m.size()) % m.size()] << endl;
}