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
    ll n;
    cin >> n;
    vector<ll> x(n), y(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans = max((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]), ans);
        }
    }

    ans *= 1000000000000ll;

    ll l = 0, r = 1000000010ll;

    while (r - l > 1)
    {
        ll mid = (l + r) / 2;

        if (mid * mid * 4 <= ans)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    string s = to_string(l);

    s.insert(s.size() - 6, ".");

    if (s[0] == '.')
    {
        s.insert(0, "0");
    }

    cout << s << endl;
}