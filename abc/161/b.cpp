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
    double n, m;

    cin >> n >> m;

    vector<double> a(n);
    double sum = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        sum += a[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= sum / (4 * m))
        {
            ans++;
        }
    }

    if (ans >= m)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}