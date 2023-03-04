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
    cin >> n;

    multiset<int> r, b;
    char c;
    int x;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> c;
        if (c == 'R')
        {
            r.insert(x);
        }
        else
        {
            b.insert(x);
        }
    }

    for (auto a : r)
    {
        cout << a << endl;
    }

    for (auto a : b)
    {
        cout << a << endl;
    }
}