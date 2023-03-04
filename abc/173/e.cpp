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
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);

    ll neg = 0;

    priority_queue<P> q;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        if (a[i] < 0)
        {
            neg++;
        }
    }

    sort(a.begin(), a.end());

    ll ans = 1;

    if (neg == n && k & 1)
    {
        for (int i = n - 1; n - i <= k; i--)
        {
            ans *= a[i];
            ans %= MOD;
        }
    }
    else
    {
        if (k & 1)
        {
            ans *= *a.rbegin();
            a.pop_back();
            k--;
        }

        for (int i = 0; i < neg; i += 2)
        {
            if (i + 1 == neg)
            {
                q.push({a[i], 1});
            }
            else
            {
                q.push({a[i] * a[i + 1], 2});
            }
        }

        for (int i = a.size() - 1; i >= neg; i -= 2)
        {
            if (i - 1 == neg - 1)
            {
                q.push({a[i], 1});
            }
            else
            {
                q.push({a[i] * a[i - 1], 2});
            }
        }

        while (k)
        {
            P p = q.top();
            q.pop();

            ans *= p.first % MOD;
            ans %= MOD;
            k -= p.second;
        }
    }

    cout << (ans + MOD) % MOD << endl;
}
