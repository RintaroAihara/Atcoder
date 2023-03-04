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

ll up = 1e11;

set<ll> ans;

void lunlun(ll x)
{

    ans.insert(10 * x + x % 10);

    if (10 * x + x % 10 <= up)
    {
        lunlun(10 * x + x % 10);
    }

    if (x % 10 - 1 >= 0)
    {
        ans.insert(10 * x + x % 10 - 1);

        if (10 * x + x % 10 - 1 <= up)
        {
            lunlun(10 * x + x % 10 - 1);
        }
    }

    if (x % 10 + 1 < 10)
    {
        ans.insert(10 * x + x % 10 + 1);

        if (10 * x + x % 10 + 1 <= up)
        {
            lunlun(10 * x + x % 10 + 1);
        }
    }
}

int main(void)
{
    ll k;
    cin >> k;

    ll count = 1;

    for (int i = 1; i < 10; i++)
    {
        ans.insert(i);
        lunlun(i);
    }

    for (auto x : ans)
    {
        if (count == k)
        {
            cout << x << endl;
            break;
        }

        count++;
    }
}