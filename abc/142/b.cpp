#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 62) - 1;

int main(void)
{
    int n, k, h;
    int i;
    int ans = 0;

    cin >> n >> k;

    rep(i, 0, n)
    {
        cin >> h;

        if (h >= k)
        {
            ans++;
        }
    }

    cout << ans << endl;
}