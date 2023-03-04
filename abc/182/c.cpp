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
    string n;
    cin >> n;

    map<ll, ll> m;

    for (int i = 0; i < n.size(); i++)
    {
        m[(n[i] - '0') % 3]++;
    }

    if (m[1] == 0 && m[0] == 0)
    {
        cout << -1 << endl;
    }
    else if (m[2] == 0 && m[0] == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        ll ans = 0;
        for (int i = 0; i <= m[1]; i++)
        {
            for (int j = 0; j <= m[2]; j++)
            {
                if ((i + j * 2) % 3 == 0)
                {
                    ans = max(ll(i + j), ans);
                }
            }
        }

        cout << m[1] + m[2] - ans << endl;
    }
}
