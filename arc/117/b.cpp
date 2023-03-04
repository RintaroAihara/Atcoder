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
#include <cassert>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

int main(void)
{
    ll n;
    cin >> n;
    set<ll> a;

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a.insert(x);
    }

    vector<ll> v;

    for (auto &&i : a)
    {
        v.push_back(i);
    }

    ll ans = v[0] + 1;

    for (int i = 1; i < a.size(); i++)
    {
        ans *= (v[i] - v[i - 1] + 1) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
}