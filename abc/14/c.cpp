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

int main(void)
{
    int n;
    cin >> n;
    vector<int> c(1000010, 0);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        c[a] += 1;
        c[b + 1] -= 1;
    }

    int ans = c[0];

    for (int i = 1; i <= 1000000; i++)
    {
        c[i] += c[i - 1];
        ans = max(c[i], ans);
    }

    cout << ans << endl;
}
