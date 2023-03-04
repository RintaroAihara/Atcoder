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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int s(int x)
{
    int ans = 0;

    while (x)
    {
        ans += x % 10;
        x /= 10;
    }

    return ans;
}

int main(void)
{
    int a, b;
    cin >> a >> b;

    if (s(a) > s(b))
    {
        cout << s(a) << endl;
    }
    else
    {
        cout << s(b) << endl;
    }
}
