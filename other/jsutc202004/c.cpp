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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    int a[3];
    int n = 0;

    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
        n += a[i];
    }

    int p[n];

    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
    }

    int block[4][4];

    memset(block, 9999, sizeof(block));

    int ans = 0;

    do
    {
        int c = 0;
        bool flag = true;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < a[i]; j++)
            {
                block[i][j] = p[c];
                c++;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < a[i]; j++)
            {
                if (block[i][j] < block[i + 1][j] && block[i][j] < block[i][j + 1])
                {
                }
                else
                {
                    flag = false;
                }
            }
        }

        if (flag)
        {
            ans++;
        }

    } while (next_permutation(p, p + n));

    cout << ans << endl;
}