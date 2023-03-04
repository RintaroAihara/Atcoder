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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    ll n, a, b;

    cin >> n >> a >> b;

    if ((b - a) % 2 == 0)
    {
        cout << (b - a) / 2 << endl;
    }
    else
    {
        cout << min({b - 1, n - a, (n * 2 - a - b + 1) / 2, (a + b - 2 + 1) / 2}) << endl;
    }
}