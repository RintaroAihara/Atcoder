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
    ll n, k;

    cin >> n >> k;

    vector<ll> a, b;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ok = INF, ng = 0;

    while (ok - ng > 1)
    {
        ll mid = (ok + ng) / 2;
        ll res = 0;

        for (auto x : a)
        {
            ll ok2 = -1, ng2 = b.size();

            while (ng2 - ok2 > 1)
            {
                ll mid2 = (ok2 + ng2) / 2;

                if (b[mid2] <= mid / x)
                {
                    ok2 = mid2;
                }
                else
                {
                    ng2 = mid2;
                }
            }

            res += ok2 + 1;
        }

        if (res >= k)
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }

    cout << ok << endl;
}
