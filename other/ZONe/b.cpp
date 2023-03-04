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
    ll D, H;
    cin >> D >> H;

    vector<ll> d(n), h(n);

    for (int i = 0; i < n; i++)
    {
        cin >> d[i] >> h[i];
    }

    double ans = 10000.0;

    for (int i = 0; i < n; i++)
    {
        double tmp = h[i] - (H - h[i]) / double(D - d[i]) * double(d[i]);
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            if ((H - h[i]) / double(D - d[i]) * double(d[j]) + tmp < h[j])
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            chmin(ans, tmp);
        }
    }

    printf("%.5lf\n", max(ans, 0.0));
}