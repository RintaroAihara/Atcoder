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
    int n;
    int ans = 0;
    ll sum = 0;

    cin >> n;

    vector<int> m(n), a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    for (int i = 1; i < n; i += 2)
    {
        ans += a[i] * 2;
    }

    ans = sum - ans;

    m[0] = ans;

    for (int i = 0; i < n; i++)
    {
        cout << m[i] << endl;
        m[i + 1] = a[i] * 2 - m[i];
    }
}