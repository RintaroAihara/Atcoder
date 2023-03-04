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
const ll INF = (1e18) + 1;

int main(void)
{
    int n;
    cin >> n;
    int i, j, k;
    int ans = 0;
    vector<int> l(n);

    rep(i, 0, n)
    {
        cin >> l[i];
    }

    sort(l.begin(), l.end());

    rep(i, 0, n)
    {
        rep(j, i + 1, n)
        {
            ll ok = j, ng = n;
            ll mid;

            while (ng - ok > 1)
            {
                mid = (ok + ng) / 2;

                if (l[mid] < l[i] + l[j])
                {
                    ok = mid;
                }
                else
                {
                    ng = mid;
                }
            }

            ans += ok - j;
        }
    }

    cout << ans << endl;
}