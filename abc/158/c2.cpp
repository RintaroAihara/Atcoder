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
#include <stack>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    int a, b;

    cin >> a >> b;

    int ans = max((int)(12.5 * a), 10 * b);

    if ((int)(ans * 0.08) == a && (int)(ans * 0.1) == b)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}