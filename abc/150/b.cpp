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
    string S;
    int i;
    int ans = 0;

    cin >> N >> S;

    rep(i, 0, N - 1)
    {
        if (S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C')
        {
            ans++;
        }
    }

    cout << ans << endl;
}