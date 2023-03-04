#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1e18) + 1;

int main(void)
{
    int n;
    vector<int> a;
    int x;
    int i, j = 1;

    cin >> n;

    rep(i, 0, n)
    {
        cin >> x;
        a.push_back(x);
    }

    rep(i, 0, n)
    {
        if (a[i] == j)
        {
            j++;
        }
    }

    if (n - j == n - 1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << n - j + 1 << endl;
    }
}