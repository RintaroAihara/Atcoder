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
    int k;
    ll ans = 0;

    cin >> k;

    for (int a = 1; a <= k; a++)
    {
        for (int b = 1; b <= k; b++)
        {
            for (int c = 1; c <= k; c++)
            {
                ans += gcd(gcd(a, b), c);
            }
        }
    }

    cout << ans << endl;
}
