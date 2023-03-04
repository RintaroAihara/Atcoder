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
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll ans = 0;
    ll x = 0;

    for (int i = 2; i <= 1000; i++)
    {
        ll tmp = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] % i == 0)
            {
                tmp++;
            }
        }

        if (tmp > x)
        {
            ans = i;
            x = tmp;
        }
    }

    cout << ans << endl;
}
