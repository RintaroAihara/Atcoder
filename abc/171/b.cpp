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
    int n, k;
    cin >> n >> k;

    vector<int> p(n);

    for (auto &&i : p)
    {
        cin >> i;
    }

    sort(p.begin(), p.end());

    int ans = 0;

    for (int i = 0; i < k; i++)
    {
        ans += p[i];
    }

    cout << ans << endl;
}
