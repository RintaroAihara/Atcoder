#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
#include <stack>
#define rep(i, s, g) for (i = s; i <= g; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1e9 + 7;

int main(void)
{
    string K;
    int D;
    int i, j, k, l;
    int d;
    static ll dp[10010][100][2];

    cin >> K >> D;

    l = K.size();

    dp[0][0][0] = 1;

    rep(i, 0, l - 1)
    {
        int nd = K[i] - '0';

        rep(j, 0, D - 1)
        {
            rep(k, 0, 1)
            {
                rep(d, 0, 9)
                {
                    int ni = i + 1, nj = (j + d) % D, nk = k;

                    if (k == 0)
                    {
                        if (nd < d)
                        {
                            continue;
                        }
                        else if (nd > d)
                        {
                            nk = 1;
                        }
                    }

                    dp[ni][nj][nk] += dp[i][j][k] % MOD;
                    dp[ni][nj][nk] %= MOD;
                }
            }
        }
    }

    cout << (dp[l][0][0] + dp[l][0][1] - 1 + MOD) % MOD << endl;
}