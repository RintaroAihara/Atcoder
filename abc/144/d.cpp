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
    double a, b, x;
    double c, d;
    double s;

    cin >> a >> b >> x;

    s = a * a * b;

    if (x <= s / 2)
    {
        c = 2 * x / (a * b);
        d = sqrt(c * c + b * b);

        printf("%.10f\n", 180 * acos(c / d) / M_PI);
    }
    else
    {
        x = s - x;
        c = 2 * x / (a * a);
        d = sqrt(c * c + a * a);

        printf("%.10f\n", 180 * acos(a / d) / M_PI);
    }
}