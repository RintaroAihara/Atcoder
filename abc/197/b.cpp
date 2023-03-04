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
    ll h, w, x, y;
    cin >> h >> w >> x >> y;
    x--, y--;

    vector<string> s(h);

    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
    }

    ll ans = 0;

    for (int i = x; i < h; i++)
    {
        if (s[i][y] == '#')
        {
            break;
        }

        ans++;
    }

    for (int i = x - 1; i >= 0; i--)
    {
        if (s[i][y] == '#')
        {
            break;
        }

        ans++;
    }

    for (int i = y - 1; i >= 0; i--)
    {
        if (s[x][i] == '#')
        {
            break;
        }

        ans++;
    }

    for (int i = y; i < w; i++)
    {
        if (s[x][i] == '#')
        {
            break;
        }

        ans++;
    }

    cout << ans - 1 << endl;
}