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
    int a, b;
    ll ans = 0;

    cin >> n;

    vector<int> g[n + 1];
    vector<bool> used(n + 1, true);
    queue<int> q;

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i < n; i++)
    {
        q.push(i);
        int d = 0;

        while (q.size())
        {
            d++;
            int count = 0;
            int s = q.front();
            q.pop();

            for (auto x : g[s])
            {
                q.push(x);

                if (d == 3 && x % 3 == 0)
                {
                    count++;
                }
            }

            if (d == 3)
            {
                if (i % 3 == 0)
                {
                    ans += q.size();
                }
                else
                {
                    ans += count;
                }
            }
        }
    }
}