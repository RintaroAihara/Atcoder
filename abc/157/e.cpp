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
    int n, q;
    string s;
    int i, j;
    set<int> alphabet[30];
    int x, y, z;
    char c;

    cin >> n >> s >> q;

    rep(i, 0, n)
    {
        alphabet[s[i] - 'a'].insert(i);
    }

    rep(i, 0, q)
    {
        cin >> x >> y;

        y--;

        if (x == 1)
        {
            cin >> c;
        }
        else
        {
            cin >> z;
            z--;
        }

        if (x == 1)
        {
            alphabet[s[y] - 'a'].erase(y);
            s[y] = c;
            alphabet[c - 'a'].insert(y);
        }
        else
        {
            int ans = 0;

            rep(j, 0, 26)
            {
                auto it = alphabet[j].lower_bound(y);

                if (z >= *it && it != alphabet[j].end())
                {
                    ans++;
                }
            }

            printf("%d\n", ans);
        }
    }
}
