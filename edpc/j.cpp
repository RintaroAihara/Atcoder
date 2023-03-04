#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#define rep(i, s, g) for (i = s; i <= g; i++)
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int N;

static double dp[310][310][310];

double cal_E(int i, int j, int k)
{
    if (dp[i][j][k] >= 0)
    {
        return dp[i][j][k];
    }

    if (i == 0 && j == 0 && k == 0)
    {
        return 0;
    }

    double tmp = 0;

    if (i > 0)
    {
        tmp += cal_E(i - 1, j, k) * i;
    }

    if (j > 0)
    {
        tmp += cal_E(i + 1, j - 1, k) * j;
    }

    if (k > 0)
    {
        tmp += cal_E(i, j + 1, k - 1) * k;
    }

    tmp += N;

    tmp *= 1.0 / (i + j + k);

    return dp[i][j][k] = tmp;
}

int main()
{
    int a;
    int one, two, three;
    int i, j, k;

    cin >> N;

    one = two = three = 0;

    rep(i, 1, N)
    {
        cin >> a;

        if (a == 1)
        {
            one++;
        }
        else if (a == 2)
        {
            two++;
        }
        else
        {
            three++;
        }
    }

    memset(dp, -1, sizeof(dp));

    printf("%.10f\n", cal_E(one, two, three));
}