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

class Position
{
public:
    ll x, y;

    bool operator==(Position a)
    {
        return (x == a.x) && (y == a.y);
    }
};

class Optimizer
{
public:
    ll N, W, K, C, P;

    vector<Position> water;
    vector<Position> house;
    vector<vector<bool>> field, searched;

    Position now;

    map<int, vector<Position>> water_to_house;

    chrono::system_clock::time_point start, end;

    Optimizer()
    {
        P = 100;
        input();
        field.assign(N, vector<bool>(N, false));
    };

    void input()
    {
        cin >> N >> W >> K >> C;

        for (int i = 0; i < W; i++)
        {
            int a, b;
            cin >> a >> b;
            water.push_back(Position{a, b});
        }

        for (int i = 0; i < K; i++)
        {
            int c, d;
            cin >> c >> d;
            house.push_back(Position{c, d});
        }
    }

    ll calc_manhattan_dist(Position a, Position b)
    {
        return abs(a.x - b.x) + abs(a.y - b.y);
    }

    void set_now(Position a)
    {
        now = a;
    }

    int search_nearhouse(int x)
    {
        ll dist = INF;
        int res = 0;

        for (int i = 0; i < water.size(); i++)
        {
            if (chmin(dist, calc_manhattan_dist(water[x], house[i])))
            {
                res = x;
            }
        }

        return res;
    }

    int search_nearwater(int x)
    {
        ll dist = INF;
        int res = 0;

        for (int i = 0; i < water.size(); i++)
        {
            if (chmin(dist, calc_manhattan_dist(house[x], water[i])))
            {
                res = x;
            }
        }

        return res;
    }

    void set_water_to_house()
    {
        for (int i = 0; i < K; i++)
        {
            water_to_house[search_nearwater(i)].push_back(house[i]);
        }
    }

    void update_water()
    {
        queue<Position> q;
        searched.assign(N, vector<bool>(N, false));

        for (auto &&i : water)
        {
            q.push(i);
        }

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};

        while (q.size())
        {
            Position p = q.front();
            q.pop();
            searched[p.x][p.y] = true;

            for (int i = 0; i < 4; i++)
            {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];

                if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                {
                    continue;
                }

                if (searched[nx][ny])
                {
                    continue;
                }

                if (field[nx][ny])
                {
                    water.push_back(Position{nx, ny});
                    q.push(Position{nx, ny});
                }
            }
        }
    }

    void move(Position goal)
    {
        if (abs(goal.x - now.x) > 0)
        {
            now.x += (goal.x - now.x) / abs(goal.x - now.x);
        }
        else if (abs(goal.y - now.y) > 0)
        {
            now.y += (goal.y - now.y) / abs(goal.y - now.y);
        }
        else
        {
            return;
        }
    }

    void excavation()
    {
        cout << now.x << " " << now.y << " " << P << endl;
    }
};

int main(void)
{
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();

    Optimizer opt;
    opt.set_water_to_house();

    for (int i = 0; i < opt.water.size(); i++)
    {
        for (auto &goal : opt.water_to_house[i])
        {
            opt.now = opt.water[i];
            while (true)
            {
                while (true)
                {
                    if (opt.field[opt.now.x][opt.now.y])
                    {
                        break;
                    }

                    opt.excavation();

                    int r;
                    cin >> r;

                    if (r == 2 || r == -1)
                    {
                        return 0;
                    }
                    else if (r == 1)
                    {
                        opt.field[opt.now.x][opt.now.y] = true;
                        break;
                    }

                    end = chrono::system_clock::now();
                    if (chrono::duration_cast<chrono::milliseconds>(end - start).count() >= 4900)
                    {
                        return 0;
                    }
                }

                if (opt.now == goal)
                {
                    break;
                }

                opt.move(goal);

                end = chrono::system_clock::now();
                if (chrono::duration_cast<chrono::milliseconds>(end - start).count() >= 4900)
                {
                    return 0;
                }
            }
        }
    }
}