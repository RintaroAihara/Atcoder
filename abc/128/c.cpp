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
    int n, m;
    int s[20][20];
    int k[20];
    int p[20];
    ll ans = 0;
    bool flag = true;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> k[i];

        for (int j = 0; j < k[i]; j++)
        {
            cin >> s[i][j];
            s[i][j]--;
        }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> p[i];
    }

    for (int i = 0; i < (1 << n); i++)
    {
        flag = true;
        for (int j = 0; j < m; j++)
        {
            int on = 0;

            for (int l = 0; l < k[j]; l++)
            {
                if ((1 << s[j][l]) & i)
                {
                    on++;
                }
            }

            if (on % 2 != p[j])
            {
                flag = false;
            }
        }

        if (flag)
        {
            ans++;
        }
    }

    cout << ans << endl;
}