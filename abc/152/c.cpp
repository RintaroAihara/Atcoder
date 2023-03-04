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
    int N;
    int p;
    int i, j;
    int ans = 0;
    int pmin = MOD;

    cin >> N;

    rep(i, 0, N - 1)
    {
        cin >> p;

        if (pmin > p)
        {
            pmin = p;
            ans++;
        }
    }

    cout << ans << endl;
}