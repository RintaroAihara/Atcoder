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

double calcConeVolume(double r, double h)
{
    return r * r * h * M_PI / 3;
}

int main(void)
{
    int n, q;
    cin >> n >> q;

    vector<double> v(100000, 0);

    for (int i = 0; i < n; i++)
    {
        double x, r, h;
        cin >> x >> r >> h;

        for (int j = x; j < int(x + h); j++)
        {
            v[j] += calcConeVolume(r * (x + h - j) / h, x + h - j) * (pow(x + h - j, 3) - pow(x + h - j - 1, 3)) / (pow(x + h - j, 3));
        }
    }

    vector<double> sum(100000, 0);

    for (int i = 0; i < 30000; i++)
    {
        sum[i + 1] = sum[i] + v[i];
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;

        printf("%.5f\n", sum[b] - sum[a]);
    }
}
