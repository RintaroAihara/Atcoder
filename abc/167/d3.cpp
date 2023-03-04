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
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n + 1), p;
    map<ll, ll> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        m[i] = INF;
    }

    ll time = 0;
    ll city = 1;
    ll start, end;

    while (true)
    {
        if (m[city] == INF)
        {
            m[city] = time;
            p.push_back(city);
            city = a[city];
        }
        else
        {
            start = m[city];
            end = time;
            break;
        }

        time++;
    }

    if (start > k)
    {
        cout << p[k] << endl;
        return 0;
    }

    cout << p[(k - start) % (start - end) + start] << endl;
}