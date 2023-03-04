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
#include <numeric>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

vector<ll> divisor(ll n)
{
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ret.push_back(i);
            if (i * i != n)
                ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}

int main(void)
{
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1, 0);
    int x = 1;

    bool flag = false;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> ans;

    for (int i = n; i >= 1; i--)
    {
        if (b[i] == a[i])
        {
            continue;
        }

        ans.push_back(i);

        vector<ll> d = divisor(i);

        for (auto &&j : d)
        {
            b[j] ^= 1;
        }
    }

    cout << ans.size() << endl;
    for (auto &&i : ans)
    {
        cout << i << endl;
    }
}