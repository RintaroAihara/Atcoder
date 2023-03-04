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
const ll INF = (1e18) + 1;

int main(void)
{
    int n;
    int i, j;
    ll ans = 0;

    cin >> n;

    vector<int> d(n);

    rep(i, 0, n)
    {
        cin >> d[i];
    }

    rep(i, 0, n)
    {
        rep(j, i + 1, n)
        {
            ans += d[i] * d[j];
        }
    }

    cout << ans << endl;
}