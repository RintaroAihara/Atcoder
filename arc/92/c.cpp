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

class Max_flow
{
private:
    struct edge
    {
        int to;
        ll cap;
        int rev;
    };

    int n;
    vector<vector<edge>> G;
    vector<int> level;
    vector<int> iter;

    void bfs(int s)
    {
        level.assign(n, -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);

        while (q.size())
        {
            int v = q.front();
            q.pop();

            for (int i = 0; i < (int)G[v].size(); i++)
            {
                edge e = G[v][i];

                if (e.cap > 0 && level[e.to] < 0)
                {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, ll f)
    {
        if (v == t)
        {
            return f;
        }

        for (int &i = iter[v]; i < (int)G[v].size(); i++)
        {
            edge &e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to])
            {
                ll d = dfs(e.to, t, min(f, e.cap));

                if (d > 0)
                {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }

        return 0;
    }

public:
    Max_flow(int n) : n(n)
    {
        G.assign(n, vector<edge>());
    }

    void add_edge(int from, int to, ll cap)
    {
        G[from].push_back({to, cap, (int)G[to].size()});
        G[to].push_back({from, 0, (int)G[from].size() - 1});
    }

    int max_flow(int s, int t)
    {
        ll flow = 0;

        while (true)
        {
            bfs(s);
            if (level[t] < 0)
            {
                return flow;
            }

            iter.assign(n, 0);
            ll f = 0;

            while ((f = dfs(s, t, INF)) > 0)
            {
                flow += f;
            }
        }
    }
};

int main(void)
{
    int n;
    cin >> n;

    vector<P> red(n), blue(n);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        red[i] = {a, b};
    }

    for (int i = 0; i < n; i++)
    {
        int c, d;
        cin >> c >> d;

        blue[i] = {c, d};
    }

    Max_flow mf(n * 2 + 2);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (red[i].first < blue[j].first && red[i].second < blue[j].second)
            {
                mf.add_edge(i, n + j, 1);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        mf.add_edge(n * 2, i, 1);
        mf.add_edge(n + i, n * 2 + 1, 1);
    }

    cout << mf.max_flow(n * 2, n * 2 + 1) << endl;
}
