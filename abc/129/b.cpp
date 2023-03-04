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
    int n;

    cin >> n;

    vector<int> w(n), sum(n + 1);

    int ans;
    ll m = INF;

    sum[0] = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
        sum[i + 1] = w[i] + sum[i];
    }

    for (int i = 0; i <= n; i++)
    {
        if (m > abs(sum[i] - sum[0] - (sum[n] - sum[i])))
        {
            ans = i;
            m = abs(sum[i] - sum[0] - (sum[n] - sum[i]));
        }
    }

    cout << m << endl;
}