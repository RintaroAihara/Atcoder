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

int main(void)
{
    ll n, k, s;
    cin >> n >> k >> s;

    vector<ll> sum(n + 1, 0);

    for (int i = 0; i < k; i++)
    {
        sum[i + 1] = s + sum[i];
    }

    for (int i = k; i < n; i++)
    {
        sum[i + 1] = s % 1000000000 + 1 + sum[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << sum[i + 1] - sum[i] << endl;
    }
}