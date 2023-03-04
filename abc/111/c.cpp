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

    map<ll, ll> even, odd;
    vector<ll> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (i & 1)
        {
            odd[v[i]]++;
        }
        else
        {
            even[v[i]]++;
        }
    }

    priority_queue<P> eq, oq;

    eq.push({0, 0});
    oq.push({0, 0});

    for (auto x : even)
    {
        eq.push({x.second, x.first});
    }

    for (auto x : odd)
    {
        oq.push({x.second, x.first});
    }

    if (eq.top().second != oq.top().second)
    {
        cout << n - eq.top().first - oq.top().first << endl;

        return 0;
    }
    else
    {
        P e1, e2, o1, o2;
        e1 = eq.top();
        eq.pop();
        o1 = oq.top();
        oq.pop();

        e2 = eq.top();
        o2 = oq.top();

        cout << n - max(e1.first + o2.first, e2.first + o1.first) << endl;
    }
}