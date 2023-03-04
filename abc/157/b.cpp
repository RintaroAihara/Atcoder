#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 62) - 1;

int main(void)
{
    int bingo[3][3];
    static bool open[3][3];
    int n;
    int b;
    int i, j, k;
    bool flag = false;

    rep(i, 0, 3)
    {
        rep(j, 0, 3)
        {
            cin >> bingo[i][j];
        }
    }

    cin >> n;

    rep(k, 0, n)
    {
        cin >> b;
        rep(i, 0, 3)
        {
            rep(j, 0, 3)
            {
                if (bingo[i][j] == b)
                {
                    open[i][j] = true;
                }
            }
        }
    }

    rep(i, 0, 3)
    {
        if (open[0][i] == true && open[1][i] == true && open[2][i] == true)
        {
            flag = true;
        }
    }

    rep(i, 0, 3)
    {
        if (open[i][0] == true && open[i][1] == true && open[i][2] == true)
        {
            flag = true;
        }
    }

    if (open[0][0] == true && open[1][1] == true && open[2][2] == true)
    {
        flag = true;
    }

    if (open[0][2] == true && open[1][1] == true && open[2][0] == true)
    {
        flag = true;
    }

    if (flag)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}