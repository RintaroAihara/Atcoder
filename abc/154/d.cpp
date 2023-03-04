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
    int N, K;
    vector<double> p;
    int i, j;
    double sum = 0;
    double maxs;

    cin >> N >> K;

    p.resize(N + 1);

    rep(i, 0, N - 1)
    {
        cin >> p[i];

        if (i < K)
        {
            sum += p[i];
            maxs = sum;
        }
        else
        {
            maxs = max(maxs, sum + p[i] - p[i - K]);
            sum = sum + p[i] - p[i - K];
        }
    }

    printf("%.7f\n", (double)(maxs + K) / 2);
}
