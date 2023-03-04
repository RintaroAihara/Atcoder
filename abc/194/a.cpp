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

    if (a + b >= 15 && b >= 8)
    {
        cout << 1 << endl;
    }
    else if (a + b >= 10 && b >= 3)
    {
        cout << 2 << endl;
    }
    else if (a + b >= 3)
    {
        cout << 3 << endl;
    }
    else
    {
        cout << 4 << endl;
    }
}