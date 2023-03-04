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
    string S, T, U;
    int A, B;

    cin >> S >> T >> A >> B >> U;

    if (S == U)
    {
        A--;
    }
    else if (T == U)
    {
        B--;
    }

    cout << A << " " << B << endl;
}