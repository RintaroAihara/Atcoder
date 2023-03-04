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
    int h, w, k;
    char c;

    static int s[100][1010];
    static int sum[100][1010];

    cin >> h >> w >> k;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> c;
            s[i][j] = c - '0';
            sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + s[i][j];
        }
    }

    ll ans = INF;

    for (int i = 0; i < (1 << (h - 1)); i++)
    {
        bitset<20> b = i;
        ll res = b.count();
        bool flag = true;
        int w1 = 0, w2;
        for (int j = 0; j < w; j++)
        {
            int h1 = 0, h2;
            w2 = j + 1;

            for (int k = 0; k < h; k++)
            {
                if (i & (1 << k))
                {
                    h2 = k + 1;

                    int tmp = sum[h2][w2] - sum[h1][w2] - sum[h2][w1] + sum[h1][w1];

                    if (tmp > k)
                    {
                        if (w2 - w1 <= 1)
                        {
                            flag = false;
                            break;
                        }
                        res++;
                        w1 = j + 1;
                        h1 = k + 1;
                    }
                }
            }

            int tmp = sum[h][w2] - sum[h1][w2] - sum[h2][w1] + sum[h1][w1];
            if (tmp > k)
            {
                res++;
                w1 = j + 1;
                h1 = k + 1;
            }
        }

        ans = min(ans, res);
    }

    cout << ans << endl;
}