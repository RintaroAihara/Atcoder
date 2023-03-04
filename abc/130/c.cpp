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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    double w, h, x, y;
    double ans;

    cin >> w >> h >> x >> y;

    ans = w * h / 2;

    cout << ans << endl;

    if (x == w / 2 && y == h / 2)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}