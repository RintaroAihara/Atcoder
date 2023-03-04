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
    double n;
    cin >> n;

    double ans = 0;
    double one = 1;
    double r = one / n;

    for (int i = 2; i <= n; i++)
    {
        double r = (double)(n - i + 1) / n;
        double tmp = one / ((one - r) * (one - r));
        tmp *= (double)(i -1) / n;

        ans += tmp;
    }

    printf("%.10f\n", ans);
    // printf("%.10f\n", tmp);
}