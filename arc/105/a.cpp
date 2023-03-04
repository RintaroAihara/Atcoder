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
    vector<int> a(10);
    ll s = 0;

    for (int i = 0; i < 4; i++)
    {
        cin >> a[i];
        s += a[i];
    }

    ll ans = 0;

    for (int i = 0; i < 1 << 4; i++)
    {
        ll x = 0;
        for (int j = 0; j < 4; j++)
        {
            if (i & 1 << j)
            {
                x += a[j];
            }
        }

        if (x == s - x)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
