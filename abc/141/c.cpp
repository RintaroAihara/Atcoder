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
#include <stack>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    int n, k, q;
    int i;
    int x;
    ll sum = 0;

    cin >> n >> k >> q;

    vector<int> a(n + 1, 0);

    rep(i, 0, q)
    {
        cin >> x;
        a[x]++;
        sum++;
    }

    rep(i, 1, n + 1)
    {
        if (a[i] + k - sum <= 0)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
}