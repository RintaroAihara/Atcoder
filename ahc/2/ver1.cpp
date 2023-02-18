#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

const int h = 50, w = 50;

vector<vector<ll>> t, p;

struct Solution
{
    vector<P> solution;
    vector<bool> searched_tile;
    ll score;

    Solution()
    {
        searched_tile.assign(h * w + 10, false);
    }
};

string change(vector<P> v)
{
    string ans;

    for (int i = 1; i < v.size(); i++)
    {
        int x = v[i].first - v[i - 1].first;
        int y = v[i].second - v[i - 1].second;

        if (x == 1 && y == 0)
        {
            ans.push_back('D');
        }
        else if (x == -1 && y == 0)
        {
            ans.push_back('U');
        }
        else if (x == 0 && y == 1)
        {
            ans.push_back('R');
        }
        else if (x == 0 && y == -1)
        {
            ans.push_back('L');
        }
    }

    return ans;
}

vector<P> beam_search(vector<Solution> S, ll beam)
{
    random_device rnd;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    chrono::system_clock::time_point start, end;

    start = chrono::system_clock::now();

    vector<P> best_ans;

    while (true)
    {
        end = chrono::system_clock::now();
        double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count());

        // cout << time << endl;
        best_ans = S[0].solution;
        if (time >= 1890000.0)
        {
            break;
        }

        vector<Solution> next_S;
        vector<ll> order;

        for (int i = 0; i < S.size(); i++)
        {
            for (int j = 0; j < 4; j++)
            {
                Solution s = S[i];
                P z = *s.solution.rbegin();
                int nx = z.first + dx[j];
                int ny = z.second + dy[j];

                if (nx < 0 || ny < 0 || nx >= h || ny >= w)
                {
                    continue;
                }

                if (s.searched_tile[t[nx][ny]])
                {
                    continue;
                }

                s.solution.push_back({nx, ny});
                s.searched_tile[t[nx][ny]] = true;
                s.score += p[nx][ny];

                order.push_back(next_S.size());
                next_S.push_back(s);
            }
        }

        if (next_S.size() == 0)
        {
            break;
        }

        // sort(order.begin(), order.end(), greater<P>{});

        for (int i = 0; i < beam; i++)
        {
            swap(order[rnd() % order.size()], order[rnd() % order.size()]);
        }

        S.clear();

        for (int i = 0; i < min(beam, ll(next_S.size())); i++)
        {
            int ni = order[i];
            S.push_back(next_S[ni]);
        }
    }

    // cout << S[0].score << endl;

    return best_ans;
}

int main(void)
{
    ll sx, sy;

    t.assign(h, vector<ll>(w));
    p.assign(h, vector<ll>(w));

    cin >> sx >> sy;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> t[i][j];
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> p[i][j];
        }
    }

    // ifstream ifs("in/0000.txt");

    // ifs >> sx >> sy;

    // for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < w; j++)
    //     {
    //         ifs >> t[i][j];
    //     }
    // }

    // for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < w; j++)
    //     {
    //         ifs >> p[i][j];
    //     }
    // }

    Solution init;
    init.score = p[sx][sy];
    init.searched_tile[t[sx][sy]] = true;
    init.solution.push_back({sx, sy});

    vector<Solution> v;
    v.push_back(init);

    cout << change(beam_search(v, 100)) << endl;
    return 0;
}