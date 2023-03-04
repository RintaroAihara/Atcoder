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
using P = pair<int, int>;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main(void)
{
    int n;
    string s;
    map<string, int> m;
    int i;
    int maxv = 0;

    cin >> n;

    rep(i, 0, n)
    {
        cin >> s;

        m[s] += 1;
    }

    for (auto &x : m)
    {
        maxv = max(maxv, x.second);
    }

    for (auto &x : m)
    {
        if (maxv == x.second)
        {
            cout << x.first << endl;
        }
    }
}