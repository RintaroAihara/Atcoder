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
    ll a, b;
    cin >> a >> b;

    vector<ll> e;

    ll sum = 0;

    for (int i = 0; i < a; i++)
    {
        e.push_back(900000 + i);
        sum += 900000 + i;
    }

    for (int i = 0; i < b - 1; i++)
    {
        e.push_back(-1 - i);
        sum += -1 - i;
    }

    e.push_back(-sum);
    // cout << -sum << endl;

    for (auto &&i : e)
    {
        cout << i << endl;
    }
}