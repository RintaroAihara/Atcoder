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
    int n, m;

    cin >> n >> m;

    set<ll> match;
    vector<ll> number = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    vector<ll> a(m);

    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        match.insert(number[a[i]]);
    }

    for (int i = n / *match.begin(); i >= 0; i--)
    {
        for (auto x : match)
        {
            if (x % *match.begin() == 0)
            {
                continue;
            }

            
        }
    }
}
