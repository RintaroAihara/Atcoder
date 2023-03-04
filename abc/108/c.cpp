#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
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
    ll n, k;

    cin >> n >> k;

    ll ans = 0;

    for (int i = 0; i < k; i++)
    {
        if (i * 3 % k == i)
        {
            ll tmp = 0;
            for (int j = i; j <= n; j += k)
            {
                if (j)
                {
                    tmp++;
                }
            }

            ans += pow(tmp, 3);
        }
    }

    cout << ans << endl;
}
