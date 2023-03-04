#include <cstdio>
#include <cstring>
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
    int n, t;
    vector<int> a, b;
    static int dp[6010][6010];
    int i, j;

    cin >> n >> t;

    a.resize(n + 1);
    b.resize(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];

        
    }

    cout << dp[n][t - 1] << endl;
}