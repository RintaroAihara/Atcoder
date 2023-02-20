#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

std::random_device seed_gen;
std::default_random_engine engine(seed_gen());

// 0.0以上1.0未満の値を等確率で発生させる
std::uniform_real_distribution<> random_dist(0.0, 1.0);

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
    ll x;
    ll y;

    bool operator==(Position a)
    {
        return (x == a.x) && (y == a.y);
    }

    bool operator!=(Position a)
    {
        return (x != a.x) || (y != a.y);
    }

    bool operator<(const Position &a) const
    {
        return (x < a.x) && (y < a.y); // 年齢を比較
    };

    Position operator+(Position a)
    {
        return Position{x + a.x, y + a.y};
    }

    Position operator-(Position a)
    {
        return Position{x - a.x, y - a.y};
    }

    Position operator*(ll a)
    {
        return Position{x * a, y * a};
    }
};

enum class Mode
{
    Test,
    Real,
};

class Test
{
public:
    ll N, W, K, C, P;
    string output;
    vector<Position> water;
    vector<Position> house;
    vector<vector<int>> is_excavated;
    vector<vector<bool>> is_house, is_water;

    Test(){};

    Test(string filename, string o)
    {
        input(filename);
        output = o;
    };

    void input(string filename)
    {
        ifstream ifs(filename);
        ifs >> N >> W >> K >> C;

        is_excavated.resize(N, vector<int>(N));
        is_house.assign(N, vector<bool>(N, false));
        is_water.assign(N, vector<bool>(N, false));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                ifs >> is_excavated[i][j];
            }
        }

        for (int i = 0; i < W; i++)
        {
            int a, b;
            ifs >> a >> b;
            water.push_back(Position{a, b});
            is_water[a][b] = true;
        }

        for (int i = 0; i < K; i++)
        {
            int c, d;
            ifs >> c >> d;
            house.push_back(Position{c, d});
            is_house[c][d] = true;
        }

        cout << "end input" << endl;
    }

    int ask(Position pos, int p)
    {
        if (is_excavated[pos.x][pos.y] <= 0)
        {
            cout << "error" << endl;
            return -1;
        }

        is_excavated[pos.x][pos.y] -= p;

        if (is_excavated[pos.x][pos.y] <= 0)
        {
            update_water();
            bool flag = true;
            for (auto &&i : house)
            {
                if (!is_water[i.x][i.y])
                {
                    flag = false;
                }
            }

            if (flag)
            {
                return 2;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 0;
        }
    }

    void update_water()
    {
        queue<Position> q;
        vector<vector<bool>> searched(N, vector<bool>(N, false));

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

                if (is_excavated[nx][ny] <= 0)
                {
                    is_water[nx][ny] = true;
                    q.push(Position{nx, ny});
                }
            }
        }
    }
};

class Annealing
{
private:
    double dist;
    double P;
    double L;
    double T;
    double time = 0;

public:
    Annealing(ll d, ll p, ll l)
    {
        dist = d;
        P = p;
        L = l;
    };

    double calc_T()
    {
        // 　低い方がより探索する
        return (time * L / (dist * 0.5)) * P;
    }

    bool is_move(ll now_score, ll next_score)
    {
        time += L;
        T = calc_T();
        // printf("%.10lf\n", T);
        // if (500 > next_score)
        // {
        //     return true;
        // }

        // if (3000 < next_score)
        // {
        //     return false;
        // }

        // return exp((now_score - next_score) / T) >= random_dist(engine);

        return exp((100 - next_score) / 1000) >= random_dist(engine);
    }
};

class Optimizer
{
public:
    ll N, W, K, C, P, L;

    vector<Position> water;
    vector<Position> house;
    vector<Position> v = {
        Position{1, 0},
        Position{-1, 0},
        Position{0, 1},
        Position{0, -1},
    };
    vector<vector<bool>> is_excavated;
    vector<vector<bool>> searched;
    vector<vector<bool>> is_water;
    vector<vector<int>> sturdiness;

    Position now;
    Position now_vector;
    Position start_pos, goal_pos;

    map<int, int> plist =
        {
            {1, 69},
            {2, 99},
            {4, 138},
            {8, 199},
            {16, 277},
            {32, 384},
            {64, 555},
            {128, 832},
    };

    ofstream ofs;

    chrono::system_clock::time_point start, end;

    Test test;
    Mode mode;

    Optimizer(Test _test, Mode _mode, int l)
    {
        // 計測開始
        start = chrono::system_clock::now();

        mode = _mode;

        if (mode == Mode::Real)
        {
            input();
        }
        else if (mode == Mode::Test)
        {
            N = _test.N;
            W = _test.W;
            K = _test.K;
            C = _test.C;
            is_water.assign(N, vector<bool>(N, false));
            is_excavated.assign(N, vector<bool>(N, false));
            sturdiness.assign(N, vector<int>(N, 0));
            water = _test.water;
            house = _test.house;
            test = _test;

            for (auto &&i : water)
            {
                is_water[i.x][i.y] = true;
            }
            ofs.open(test.output, std::ios::out);
        }

        P = plist[C];
        L = l;
    };

    void input()
    {
        cin >> N >> W >> K >> C;

        is_water.assign(N, vector<bool>(N, false));
        is_excavated.assign(N, vector<bool>(N, false));
        sturdiness.assign(N, vector<int>(N, 0));

        for (int i = 0; i < W; i++)
        {
            int a, b;
            cin >> a >> b;
            water.push_back(Position{a, b});
            is_water[a][b] = true;
        }

        for (int i = 0; i < K; i++)
        {
            int c, d;
            cin >> c >> d;
            house.push_back(Position{c, d});
        }
    }

    int ask(Position pos)
    {
        if (is_excavated[pos.x][pos.y])
        {
            return 1;
        }

        int r;
        if (mode == Mode::Test)
        {
            r = test.ask(_excavation(pos), P);
        }
        else if (mode == Mode::Real)
        {
            excavation(pos);
            cin >> r;
        }

        if (r == 1)
        {
            is_excavated[pos.x][pos.y] = true;
        }

        return r;
    }

    void solve()
    {
        ll z = 0;
        for (int i = 0; i < W; i++)
        {
            while (true)
            {
                int r = ask(water[i]);

                if (r == 2 || r == -1)
                {
                    return;
                }
                else if (r == 1)
                {
                    break;
                }
            }
        }

        for (int i = 0; i < K; i++)
        {
            while (true)
            {
                int r = ask(house[i]);

                if (r == 2 || r == -1)
                {
                    return;
                }
                else if (r == 1)
                {
                    break;
                }
            }
        }

        while (true)
        {
            int goal_i = search_next_house();
            start_pos = water[search_nearwater(goal_i)];
            now = start_pos;

            priority_queue<pair<ll, Position>, vector<pair<ll, Position>>, greater<pair<ll, Position>>> q;
            q.push({calc_manhattan_dist(now, goal_pos), now});

            Annealing ann(calc_manhattan_dist(now, goal_pos), P, L);

            while (true)
            {
                Position next_direction = decesion_next_direction();
                // cout << now.x << " " << now.y << endl;

                if (next_direction == Position{0, 0})
                {
                    while (q.size())
                    {
                        now = q.top().second;
                        q.pop();
                        next_direction = decesion_next_direction();

                        if (next_direction != Position{0, 0})
                        {
                            break;
                        }
                    }
                }
                else
                {
                    bool connect_flag = false;
                    bool continue_flag = true;
                    for (int i = 1; i <= L; i++)
                    {
                        Position next = now + next_direction * i;
                        if (continue_flag)
                        {
                            while (true)
                            {
                                int r = ask(next);

                                if (r == 2 || r == -1)
                                {
                                    return;
                                }
                                else if (r == 1)
                                {
                                    continue_flag &= ann.is_move(sturdiness[now.x][now.y], sturdiness[next.x][next.y]);
                                    z++;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            sturdiness[next.x][next.y] = sturdiness[next.x - next_direction.x][next.y - next_direction.y];
                        }

                        connect_flag = is_connect(next);

                        if (connect_flag)
                        {
                            break;
                        }
                    }

                    if (connect_flag)
                    {
                        cout << "next" << endl;
                        update_water();
                        break;
                    }

                    if (is_excavated[now.x + next_direction.x * L][now.y + next_direction.y * L] && ann.is_move(sturdiness[now.x][now.y], sturdiness[now.x + next_direction.x * L][now.y + next_direction.y * L]))
                    {
                        now = now + next_direction * L;
                        q.push({calc_manhattan_dist(now, goal_pos), now});
                    }
                    else
                    {
                    }
                }

                end = chrono::system_clock::now();
                if (chrono::duration_cast<chrono::milliseconds>(end - start).count() >= 4900)
                {
                    cout << z << endl;

                    return;
                }
            }

            end = chrono::system_clock::now();
            if (chrono::duration_cast<chrono::milliseconds>(end - start).count() >= 4900)
            {
                return;
            }
        }
    }

    bool is_region(Position p)
    {
        if (p.x >= 0 && p.y >= 0 && p.x < N && p.y < N)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool is_connect(Position p)
    {
        bool flag = false;
        flag = (p == goal_pos);
        for (int j = 0; j < v.size(); j++)
        {
            if (!is_region(p + v[j]))
            {
                continue;
            }

            flag = (p + v[j] == goal_pos);
            if (flag)
            {
                break;
            }
        }

        return flag;
    }

    bool is_change_search_point(Position p)
    {
        double dist_start = calc_manhattan_dist(start_pos, goal_pos);
        double dist_now = calc_manhattan_dist(now, goal_pos);
        return !(((dist_now / dist_start) - 1.0) <= random_dist(engine));
    }

    ll calc_manhattan_dist(Position a, Position b)
    {
        return abs(a.x - b.x) + abs(a.y - b.y);
    }

    int search_nearhouse(int x)
    {
        ll dist = INF;
        int res = 0;

        for (int i = 0; i < house.size(); i++)
        {
            if (chmin(dist, calc_manhattan_dist(water[x], house[i])))
            {
                res = i;
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
                res = i;
            }
        }

        return res;
    }

    int search_next_house()
    {
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
        for (int i = 0; i < house.size(); i++)
        {
            if (!is_water[house[i].x][house[i].y])
            {
                // 家iから最も近い水源の距離
                ll d = calc_manhattan_dist(house[i], water[search_nearwater(i)]);
                q.push({d, i});
            }
        }

        goal_pos = house[q.top().second];

        return q.top().second;
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

                if (is_excavated[nx][ny])
                {
                    water.push_back(Position{nx, ny});
                    is_water[nx][ny] = true;
                    q.push(Position{nx, ny});
                }
            }
        }
    }

    Position decesion_next_direction()
    {
        Position direction = goal_pos - now;
        ll bestscore = 0;
        ll best_i = 0;

        vector<pair<ll, ll>> scorelist;

        for (int i = 0; i < v.size(); i++)
        {
            Position next = now + v[i] * L;
            if (!is_region(next))
            {
                continue;
            }

            if (sturdiness[next.x][next.y] > 0 && next != goal_pos)
            {
                continue;
            }

            ll score = 0;
            if (abs(v[i].x) > 0)
            {
                score = direction.x / v[i].x;
            }
            else
            {
                score = direction.y / v[i].y;
            }

            scorelist.push_back({score, i});
        }

        if (scorelist.size())
        {
            sort(scorelist.begin(), scorelist.end(), greater<pair<ll, ll>>());

            return v[scorelist[0].second];
        }
        else
        {
            return Position{0, 0};
        }
    }

    Position decesion_move_positon()
    {
        Position direction = goal_pos - now;
        ll bestscore = 0;
        ll best_i = 0;

        vector<pair<ll, ll>> scorelist;

        for (int i = 0; i < v.size(); i++)
        {
            Position next = now + v[i];
            if (!is_region(next))
            {
                continue;
            }

            ll score = 0;
            if (abs(v[i].x) > 0)
            {
                score = direction.x / v[i].x;
            }
            else
            {
                score = direction.y / v[i].y;
            }

            scorelist.push_back({score, i});
        }

        sort(scorelist.begin(), scorelist.end(), greater<pair<ll, ll>>());

        return now + v[scorelist[0].second];
    }

    void move(Position pos)
    {
        now = pos;
    }

    void excavation(Position pos)
    {
        sturdiness[pos.x][pos.y] = min(P + sturdiness[pos.x][pos.y], 5000ll);
        cout << pos.x << " " << pos.y << " " << P << endl;
    }

    Position _excavation(Position pos)
    {
        sturdiness[pos.x][pos.y] = min(P + sturdiness[pos.x][pos.y], 5000ll);
        ofs << pos.x << " " << pos.y << " " << P << endl;
        return pos;
    }
};

int main(int argc, char *argv[])
{
    Test test(argv[1], "output.txt");
    Optimizer opt(test, Mode::Test, 3);
    opt.solve();
}