#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1e18) + 1;

int main(void)
{
    int n;
    vector<int> a(20);
    int x[20][20];
    int y[20][20];
    vector<bool> o(20);
    int i, j, k;
    int bit;
    int ans = 0;
    int count;
    bool flag;

    cin >> n;

   
    rep(i, 1, n + 1)
    {
        cin >> a.at(i);

        rep(j, 1, a[i] + 1)
        {
            cin >> x[i][j] >> y[i][j];
        }
    }

    rep(bit, 0, 1 << n)
    {
        flag = true;
        rep(i, 1, n + 1)
        {
            rep(j, 1, a[i] + 1)
            {
                if (!(bit & 1 << (i - 1)))
                {
                    continue;
                }

                if ((bit >> (x[i][j] - 1) & 1) ^ y[i][j])
                {
                    flag = false;
                }
            }
        }

        if (flag)
        {
            count = 0;
            rep(i, 0, n)
            {
                if (bit >> i & 1)
                {
                    count++;
                }
            }
            ans = max(ans, count);
        }
    }

    cout << ans << endl;
}