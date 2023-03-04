#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#define rep(i, s, g) for (i = s; i <= g; i++)
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main(void)
{
    int N, K, M;
    int A;
    int i, j;
    int sum = 0;

    cin >> N >> K >> M;

    rep(i, 1, N - 1)
    {
        cin >> A;
        sum += A;
    }

    if (M * N - sum <= K && M * N - sum >= 0)
    {
        cout << M * N - sum << endl;
    }
    else if (M * N - sum <= 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}