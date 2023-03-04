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
    int x, n;

    cin >> x >> n;
    set<int> p;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        p.insert(a);
    }

    ll ans = 111;

    for (int i = 110; i >= -10; i--)
    {
        if (abs(x - ans) >= abs(x - i) && p.find(i) == p.end())
        {
            ans = i;
        }
    }

    cout << ans << endl;
}
