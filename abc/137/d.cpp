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
    int n, m;
    cin >> n >> m;

    priority_queue<int> q;
    map<int, vector<int>> ma;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        ma[a].push_back(b);
    }

    ll ans = 0;

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = 0; j < ma[m - i].size(); j++)
        {
            q.push(ma[m - i][j]);
        }

        if (q.size())
        {
            ans += q.top();
            q.pop();
        }
    }

    cout << ans << endl;
}