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
    double x0, y0, x2, y2;
    cin >> x0 >> y0 >> x2 >> y2;

    double x, y;
    x = (x0 + x2) / (double)2;
    y = (y0 + y2) / (double)2;

    double t = 2 * M_PI / (double)n;

    double x_, y_;

    x_ = x0 - x;
    y_ = y0 - y;

    printf("%.7lf %.7lf\n", x + x_ * cos(t) - y_ * sin(t), y + x_ * sin(t) + y_ * cos(t));
}