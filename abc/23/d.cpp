#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = ll(1e18) + 1;

int main(void)
{
    int n;
    vector<ll> h;
    vector<ll> s;
    ll i, j;
    int x, y;

    cin >> n;

    rep(i, 0, n)
    {
        cin >> x >> y;

        h.push_back(x);
        s.push_back(y);
    }

    ll ok = INF, ng = 0;

    while (ok - ng > 1)
    {
        ll mid = (ok + ng) / 2;
        bool flag = true;
        vector<ll> t;

        rep(i, 0, n)
        {
            if (mid - h[i] < 0)
            {
                flag = false;
                break;
            }

            t.push_back((mid - h[i]) / s[i]);
        }

        if (flag)
        {
            sort(t.begin(), t.end());

            rep(i, 0, n)
            {
                if (t[i] < i)
                {
                    flag = false;
                    break;
                }
            }
        }

        if (flag)
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