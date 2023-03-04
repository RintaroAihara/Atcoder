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
    int n;
    string s;
    ll ans;
    vector<int> r, g, b;

    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R')
        {
            r.push_back(i);
        }
        else if (s[i] == 'G')
        {
            g.push_back(i);
        }
        else
        {
            b.push_back(i);
        }
    }

    ans = r.size() * b.size() * g.size();

    for (auto x : r)
    {
        for (auto y : g)
        {
            int i, j;
            i = min(x, y);
            j = max(x, y);

            int res = 0;

            if ((i + j) % 2 == 0)
            {
                if (s[(i + j) / 2] == 'B')
                {
                    res++;
                }
            }

            if (2 * j - i < n)
            {
                if (s[2 * j - i] == 'B')
                {
                    res++;
                }
            }

            if (2 * i - j >= 0)
            {
                if (s[2 * i - j] == 'B')
                {
                    res++;
                }
            }

            ans -= res;
        }
    }

    cout << ans << endl;
}
