#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1e18) + 1;

int main(void)
{
    ll n;
    ll ans = 0;

    cin >> n;

    if (n % 2 == 0)
    {
        n /= 2;
        while (n / 5 > 0)
        {
            ans += n / 5;
            n /= 5;
        }

        cout << ans << endl;
    }
    else
    {
        cout << ans << endl;
    }
}