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

int main(void)
{
    ll k;
    cin >> k;

    ll ans = 0;

    for (ll i = 1; i <= k; i++)
    {
        for (ll j = i; i * j * j <= k; j++)
        {
            for (ll l = j; i * j * l <= k; l++)
            {
                if (i == j && j == l)
                {
                    ans += 1;
                }
                else if (i == j || j == l)
                {
                    ans += 3;
                }
                else
                {
                    ans += 6;
                }
            }
        }
    }

    cout << ans << endl;
}