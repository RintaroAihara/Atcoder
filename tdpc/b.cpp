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
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

template <typename T>
bool chmin(T &x, T y)
{
    x = min(x, y);
    return x == y;
}

template <typename T>
bool chmax(T &x, T y)
{
    x = max(x, y);
    return x == y;
}

int main(void)
{
    ll A, B;
    cin >> A >> B;
    vector<ll> a(A, 0), b(B, 0);

    for (int i = 0; i < A; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < B; i++)
    {
        cin >> b[i];
    }

    vector<vector<ll>> dp(A + 1, vector<ll>(B + 1, 0));

    for (int i = A; i >= 0; i--)
    {
        for (int j = B; j >= 0; j--)
        {
            if (i == A && j == B)
            {
                continue;
            }

            if ((i + j) % 2 == 0)
            {
                if (i == A)
                {
                    dp[i][j] = dp[i][j + 1] + b[j];
                }
                else if (j == B)
                {
                    dp[i][j] = dp[i + 1][j] + a[i];
                }
                else
                {
                    
                }
            }
            else
            {
            }
        }
    }
}