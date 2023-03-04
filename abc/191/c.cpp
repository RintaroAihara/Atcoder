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

int main(void)
{
    ll h, w;
    cin >> h >> w;

    vector<string> s(h), s2(h * 3);
    vector<vector<bool>> edge(h * 3, vector<bool>(w * 3, false));

    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
    }

    for (int i = 0; i < h; i++)
    {
        string tmp = "";
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] == '#')
            {
                tmp += "###";
            }
            else
            {
                tmp += "...";
            }
        }

        for (int j = 0; j < 3; j++)
        {
            s2[i * 3 + j] = tmp;
        }
    }

    // for (int i = 0; i < h * 3; i++)
    // {
    //     cout << s2[i] << endl;
    // }

    for (int i = 0; i < h * 3; i++)
    {
        for (int j = 0; j < w * 3; j++)
        {
            if (s2[i][j] == '#')
            {
                for (int k = -1; k < 2; k++)
                {
                    for (int l = -1; l < 2; l++)
                    {
                        if (s2[i + k][j + l] == '.')
                        {
                            edge[i][j] = true;
                        }
                    }
                }
            }
        }
    }

    ll ans = 0;

    int dx[4] = {0, 1, 1, 1};
    int dy[4] = {1, 1, 0, -1};

    for (int i = 0; i < h * 3; i++)
    {
        for (int j = 0; j < w * 3; j++)
        {

            if (edge[i][j])
            {
                bool flag = true;
                for (int k = 0; k < 4; k++)
                {
                    ll nx = i + dx[k], ny = j + dy[k];
                    ll mx = i - dx[k], my = j - dy[k];

                    if (edge[nx][ny] && edge[mx][my])
                    {
                        flag = false;
                    }
                }

                if (flag)
                {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}
