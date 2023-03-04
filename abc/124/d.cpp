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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    int n, k;
    string s;

    cin >> n >> k >> s;

    vector<P> p;
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            if (res == 0)
            {
                p.push_back(P(i, 0));
            }

            res++;
        }
        else
        {
            if (res > 0)
            {
                p.back().second = res;
                res = 0;
            }
        }
    }

    if (res > 0)
    {
        p.back().second = res;
        res = 0;
    }

    if (s[0] == '0')
    {
        p.insert(p.begin(), P(0, 0));
    }

    if (s[n - 1] == '0')
    {
        p.push_back(P(n, 0));
    }

    if (k >= p.size() - 1)
    {
        cout << n << endl;
        return 0;
    }

    ll ans = 0;

    for (int i = 0; i + k < p.size(); i++)
    {
        ans = max(ans, p[i + k].first + p[i + k].second - p[i].first);
    }

    cout << ans << endl;
}