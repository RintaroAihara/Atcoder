#include <cstdio>
#include <cstring>
#include <utility>
#include <iostream>
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
const ll INF = (1e18) + 1;

vector<int> G[100010];
vector<bool> serched(100010, false);
map<P, int> color;
vector<P> vp;
vector<int> vc(100010, 0);
int ans = 0;

void bfs(int s)
{
    queue<int> q;
    int p;
    int c;

    q.push(s);

    while (q.size())
    {
        p = q.front();
        q.pop();

        serched[p] = true;

        c = 1;

        for (auto &x : G[p])
        {
            if (serched[x] == false)
            {
                q.push(x);

                if (vc[p] == c)
                {
                    c++;
                }

                color.insert(make_pair(P(p, x), c));
                color.insert(make_pair(P(x, p), c));
                vc[x] = c;
                ans = max(ans, c);
                c++;
            }
        }
    }
}

int main(void)
{
    int n;
    int a, b;
    int i;

    cin >> n;

    rep(i, 1, n)
    {
        cin >> a >> b;

        G[a].emplace_back(b);
        G[b].emplace_back(a);
        vp.emplace_back(a, b);
    }

    bfs(1);

    cout << ans << endl;

    for (auto &x : vp)
    {
        cout << color.at(x) << endl;
    }
}