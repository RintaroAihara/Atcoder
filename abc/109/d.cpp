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
#include <tuple>
#include <numeric>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

struct ans
{
    int x, y;
};

int main(void)
{
    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> a[i][j];
        }
    }

    bool flag = false;
    vector<ans> res;

    for (int i = 0; i < h; i += 2)
    {
        for (int j = 0; j < w; j++)
        {
            if (a[i][j] % 2 && !flag)
            {
                res.push_back({i, j});
                flag = true;
            }
            else if (a[i][j] % 2 && flag)
            {
                res.push_back({i, j});
                flag = false;
            }
            else if (flag)
            {
                res.push_back({i, j});
                res.push_back({i, j});
            }
        }

        if (i + 1 >= h)
        {
            break;
        }

        for (int j = w - 1; j >= 0; j--)
        {
            if (a[i + 1][j] % 2 && !flag)
            {
                res.push_back({i + 1, j});
                flag = true;
            }
            else if (a[i + 1][j] % 2 && flag)
            {
                res.push_back({i + 1, j});
                flag = false;
            }
            else if (flag)
            {
                res.push_back({i + 1, j});
                res.push_back({i + 1, j});
            }
        }
    }

    cout << res.size() / 2 << endl;

    for (int i = 0; i < res.size() / 2; i++)
    {
        printf("%d %d %d %d\n", res[i * 2].x + 1, res[i * 2].y + 1, res[i * 2 + 1].x + 1, res[i * 2 + 1].y + 1);
    }

    // for (auto &&i : res)
    // {
    //     printf("%d %d\n", i.x + 1, i.y + 1);
    // }
}