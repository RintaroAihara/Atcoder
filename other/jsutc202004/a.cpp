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
    int s, l, r;

    cin >> s >> l >> r;

    if (l - s >= 0)
    {
        cout << l << endl;
    }
    else if (s - r >= 0)
    {
        cout << r << endl;
    }
    else
    {
        cout << s << endl;
    }
}