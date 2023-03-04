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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    int a[10];
    int ans = MOD;
    int p[5];

    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
        p[i] = i;
    }

    do
    {
        int res = 0;

        for (int i = 0; i < 5; i++)
        {
            res = (res + 9) / 10;
            res *= 10;
            res += a[p[i]];
        }

        ans = min(ans, res);

    } while (next_permutation(p, p + 5));

    cout << ans << endl;
}