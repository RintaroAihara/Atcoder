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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    int n, k;
    double ans = 0;

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        int res = i;
        double p = 1.0 / n;

        while (res < k)
        {
            res *= 2;
            p /= 2;
        }

        ans += p;
    }

    printf("%.10f\n", ans);
}