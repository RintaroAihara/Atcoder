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
    int h, w;
    char maze[2010][2010];
    static int length[2010][2010], width[2010][2010];

    int ans = 0;
    int l;

    cin >> h >> w;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> maze[i][j];
        }
    }

    for (int i = 0; i < h; i++)
    {
        int count = 0;
        for (int j = 0; j < w; j++)
        {
            if (maze[i][j] == '#')
            {
                if (count > 0)
                {
                    length[i][j - 1] = count;
                    count = 0;
                }
            }
            else if (j + 1 == w)
            {
                count++;
                length[i][j] = count;
            }
            else
            {
                count++;
            }
        }
    }

    for (int i = 0; i < h; i++)
    {
        l = 0;
        for (int j = w - 1; j >= 0; j--)
        {
            if (length[i][j] > 0)
            {
                l = length[i][j];
            }

            if (maze[i][j] == '.')
            {
                length[i][j] = l;
            }
            else
            {
                l = 0;
            }
        }
    }

    for (int j = 0; j < w; j++)
    {
        int count = 0;
        for (int i = 0; i < h; i++)
        {
            if (maze[i][j] == '#')
            {
                if (count > 0)
                {
                    width[i - 1][j] = count;
                    count = 0;
                }
            }
            else if (i + 1 == h)
            {
                count++;
                width[i][j] = count;
            }
            else
            {
                count++;
            }
        }
    }

    for (int j = 0; j < w; j++)
    {
        l = 0;

        for (int i = h - 1; i >= 0; i--)
        {
            if (width[i][j] > 0)
            {
                l = width[i][j];
            }

            if (maze[i][j] == '.')
            {
                width[i][j] = l;
            }
            else
            {
                l = 0;
            }
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            ans = max(ans, length[i][j] + width[i][j] - 1);
        }
    }

    cout << ans << endl;
}