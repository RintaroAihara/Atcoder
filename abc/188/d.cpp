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
    ll n, C;
    cin >> n >> C;

    map<ll, ll> sum;

    ll f = INF;

    for (int i = 0; i < n; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        f = min(a, f);
        a--;

        sum[a] += c;
        sum[b] -= c;
    }

    ll tmp = 0;

    for (auto &&i : sum)
    {
        i.second += tmp;
        tmp = i.second;
    }

    for (auto &&i : sum)
    {
        i.second = min(C, i.second);
    }

    ll ans = 0;
    ll day = f;
    tmp = 0;

    for (auto &&i : sum)
    {
        ans += (i.first - day) * tmp;
        day = i.first;
        tmp = i.second;
    }

    cout << ans << endl;
}
