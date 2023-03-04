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
#include <stack>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    int n;
    double a;
    double ans = 0;
    int i;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> a;
        ans += 1 / a;
    }

    ans = 1 / ans;

    printf("%.6f\n", ans);
}