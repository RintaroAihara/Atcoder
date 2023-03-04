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
    vector<double> x, y;
    vector<int> perm;
    int i;
    double z;
    double ans = 0;
    int sum = 0;

    cin >> n;

    x.resize(n + 1);
    y.resize(n + 1);

    rep(i, 1, n + 1)
    {
        cin >> x[i] >> y[i];
        perm.push_back(i);
    }

    do
    {
        rep(i, 0, n - 1)
        {
            z = (x[perm[i]] - x[perm[i + 1]]) * (x[perm[i]] - x[perm[i + 1]]) + (y[perm[i]] - y[perm[i + 1]]) * (y[perm[i]] - y[perm[i + 1]]);
            ans += sqrt(z);
        }

        sum++;
    } while (next_permutation(perm.begin(), perm.end()));

    printf("%.10lf\n", ans / sum);
}