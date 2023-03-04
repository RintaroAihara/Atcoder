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
    double a, b;
    double h, m;
    double at, bt, t;
    double ans;

    cin >> a >> b >> h >> m;

    at = M_PI * h / 6 + M_PI * m / 360;
    bt = M_PI * m / 30;

    t = min(abs(at - bt), 2 * M_PI - abs(at - bt));

    ans = a * a + b * b - 2 * a * b * cos(t);

    printf("%.10f\n", sqrt(ans));
}
