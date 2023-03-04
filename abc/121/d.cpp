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
    ll a, b;

    vector<ll> ans(41, 0);

    cin >> a >> b;

    a--;

    for (int i = 1; i <= ceil(log2(b)) + 1; i++)
    {
        ans[i] += (b / (ll)pow(2, i)) * (ll)pow(2, i) / 2 + max(b % (ll)pow(2, i) - ((ll)pow(2, i - 1) - 1), 0ll);
    }

    for (int i = 1; i <= ceil(log2(a)) + 1; i++)
    {
        ans[i] -= (a / (ll)pow(2, i)) * (ll)pow(2, i) / 2 + max(a % (ll)pow(2, i) - ((ll)pow(2, i - 1) - 1), 0ll);
    }

    ll res = 0;

    for (int i = 1; i < 41; i++)
    {
        res += (ans[i] % 2) * pow(2, i - 1);
    }

    cout << res << endl;
}