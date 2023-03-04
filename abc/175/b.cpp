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
    ll n;
    cin >> n;
    vector<ll> l(n);

    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (l[i] + l[j] > l[k] && l[i] + l[k] > l[j] && l[j] + l[k] > l[i] && l[i] != l[j] && l[j] != l[k] && l[k] != l[i])
                {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}
