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

chrono::system_clock::time_point start;

vector<P> best_ans;
ll best_score = 0;

void dfs(vector<P> solution, vector<bool> searched_tile, ll score)
{
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    auto end = chrono::system_clock::now();
    double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count());

    if (chmax(best_score, score))
    {
        best_ans = solution;
    }

    // cout << time << endl;
    if (time >= 1950000.0)
    {
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        P z = *solution.rbegin();
        int nx = z.first + dx[i];
        int ny = z.second + dy[i];

        if (nx < 0 || ny < 0 || nx >= h || ny >= w)
        {
            continue;
        }

        if (searched_tile[t[nx][ny]])
        {
            continue;
        }

        solution.push_back({nx, ny});
        searched_tile[t[nx][ny]] = true;
        score += p[nx][ny];

        dfs(solution, searched_tile, score);
    }
}

string change(vector<P> v = best_ans)
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

int main(void)
{
    start = chrono::system_clock::now();

    ll sx, sy;

    t.assign(h, vector<ll>(w));
    p.assign(h, vector<ll>(w));

    // cin >> sx >> sy;

    // for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < w; j++)
    //     {
    //         cin >> t[i][j];
    //     }
    // }

    // for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < w; j++)
    //     {
    //         cin >> p[i][j];
    //     }
    // }

    ifstream ifs("in/0000.txt");

    ifs >> sx >> sy;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            ifs >> t[i][j];
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            ifs >> p[i][j];
        }
    }

    vector<P> init;
    vector<bool> searched_tile(h * w, false);
    searched_tile[t[sx][sy]] = true;
    ll score = p[sx][sy];
    best_score = score;

    init.push_back({sx, sy});

    dfs(init, searched_tile, score);

    cout << change() << endl;

    return 0;
}