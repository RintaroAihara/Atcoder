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
    int N;
    vector<int> A;
    int i, j;

    cin >> N;

    A.resize(N);

    rep(i, 0, N - 1)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    rep(i, 1, N - 1)
    {
        if (A[i] == A[i - 1])
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}