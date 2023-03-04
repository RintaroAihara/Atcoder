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
    double v;
    int i;
    priority_queue<double, vector<double>, greater<double>> pot;
    double ans = 0;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> v;

        pot.push(v);
    }

    while (pot.size() != 1)
    {
        double x, y;

        x = pot.top();
        pot.pop();
        y = pot.top();
        pot.pop();

        ans += (x + y) / 2;

        pot.push((x + y) / 2);
    }

    printf("%.6f\n", pot.top());
}