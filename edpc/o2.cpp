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
#include <cassert>
#include <time.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int N;
bool a[21][21];
int dp[1 << 21];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];

    dp[0] = 1;
    int c = 0;
    for (int S = 1; S < 1 << N; S++)
    {
        int i = __builtin_popcount(S);
        for (int j = 0; j < N; j++)
        {
            if (S >> j & 1 && a[i - 1][j] == 1)
            {
                c++;
                dp[S] += dp[S ^ 1 << j];
                dp[S] %= MOD;
            }
        }
    }
    cout << c << endl;
    cout << dp[(1 << N) - 1] << endl;

    return 0;
}