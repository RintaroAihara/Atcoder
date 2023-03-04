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
    ll n, k, c;
    string s;

    cin >> n >> k >> c >> s;

    deque<int> l, r;

    ll count = 1;

    for (ll i = 0; i < n; i++)
    {
        if (s[i] == 'o')
        {
            l.push_back(i);
            count++;

            if (count > k)
            {
                break;
            }

            i += c;
        }
    }

    count = 1;

    for (ll i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'o')
        {
            r.push_front(i);
            count++;

            if (count > k)
            {
                break;
            }

            i -= c;
        }
    }

    count = 1;

    for (int i = 0; i < k; i++)
    {

        if (l[i] == r[i])
        {
            cout << l[i] + 1 << endl;
        }
    }
}