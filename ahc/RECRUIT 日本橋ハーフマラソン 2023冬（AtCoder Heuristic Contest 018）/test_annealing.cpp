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
        house.resize(W);
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

        for (int i = W; i < W + K; i++)
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

class unionfind
{
private:
    vector<long long> d;

public:
    vector<bool> is_water;
    unionfind(){};

    void init(ll w, ll k)
    {
        d.assign(w + k, -1);
        is_water.assign(w + k, false);

        for (int i = 0; i < w; i++)
        {
            is_water[i] = true;
        }
    }

    bool same(long long x, long long y)
    {
        return root(x) == root(y);
    }

    long long root(long long x)
    {
        if (d[x] < 0)
        {
            return x;
        }
        else
        {
            return d[x] = root(d[x]);
        }
    }

    bool unite(long long x, long long y)
    {
        x = root(x);
        y = root(y);

        if (x == y)
        {
            return false;
        }

        if (d[x] > d[y])
        {
            swap(x, y);
        }

        is_water[x] = is_water[x] | is_water[y];
        is_water[y] = is_water[x] | is_water[y];

        d[x] += d[y];
        d[y] = x;
        return true;
    }

    long long size(long long x)
    {
        return -d[root(x)];
    }
};

class Annealing
{
private:
    double dist;
    double P;
    double L;
    double T;
    int time;

public:
    Annealing(){};
    Annealing(ll p, ll l)
    {
        P = p;
        L = l;
        init();
    };

    void init()
    {
        time = 0;
    }

    int calc_T()
    {
        // 　低い方がより探索する
        return time;
    }

    bool is_move(ll now_score, ll next_score)
    {
        time += 1;
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

        return exp((500 + T - next_score) / 1000) >= random_dist(engine);
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
    vector<Position> pos_list;
    vector<int> goal_list;
    vector<vector<Position>> location_list;
    vector<vector<Position>> start_position_list;
    vector<vector<bool>> is_excavated;
    vector<vector<bool>> searched;
    vector<vector<bool>> is_water;
    vector<vector<int>> sturdiness;
    vector<vector<int>> field;

    vector<Annealing> annealing_list;

    unionfind uf;

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
            uf.init(W, K);
            annealing_list.resize(W + K);
            pos_list.resize(W + K);
            house.resize(W);
            goal_list.assign(W + K, -1);
            location_list.assign(N, vector<Position>());
            start_position_list.assign(N, vector<Position>());
            is_water.assign(N, vector<bool>(N, false));
            is_excavated.assign(N, vector<bool>(N, false));
            sturdiness.assign(N, vector<int>(N, 0));
            field.assign(N, vector<int>(N, -1));
            water = _test.water;
            house = _test.house;
            test = _test;

            for (auto &&i : water)
            {
                is_water[i.x][i.y] = true;
            }

            for (int i = 0; i < W; i++)
            {
                field[water[i].x][water[i].y] = i;
                location_list[i].push_back(water[i]);
                start_position_list[i].push_back(water[i]);
                annealing_list[i] = Annealing(P, L);
            }

            for (int i = W; i < W + K; i++)
            {
                field[house[i].x][house[i].y] = i;
                location_list[i].push_back(house[i]);
                start_position_list[i].push_back(house[i]);
                annealing_list[i] = Annealing(P, L);
            }

            ofs.open(test.output, std::ios::out);
        }

        P = plist[C];
        L = l;
    };

    void input()
    {
        cin >> N >> W >> K >> C;

        uf.init(W, K);
        annealing_list.resize(W + K);
        pos_list.resize(W + K);
        house.resize(W);
        goal_list.assign(W + K, -1);
        location_list.assign(N, vector<Position>());
        start_position_list.assign(N, vector<Position>());
        is_water.assign(N, vector<bool>(N, false));
        is_excavated.assign(N, vector<bool>(N, false));
        sturdiness.assign(N, vector<int>(N, 0));
        field.assign(N, vector<int>(N, -1));

        for (int i = 0; i < W; i++)
        {
            int a, b;
            cin >> a >> b;
            water.push_back(Position{a, b});
            is_water[a][b] = true;
            field[a][b] = i;
            location_list[i].push_back(water[i]);
            start_position_list[i].push_back(house[i]);
            annealing_list[i] = Annealing(P, L);
        }

        for (int i = W; i < W + K; i++)
        {
            int c, d;
            cin >> c >> d;
            house.push_back(Position{c, d});
            field[c][d] = i;
            location_list[i].push_back(house[i]);
            start_position_list[i].push_back(house[i]);
            annealing_list[i] = Annealing(P, L);
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
                    field[water[i].x][water[i].y] = i;
                    break;
                }
            }
        }

        for (int i = W; i < W + K; i++)
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
                    field[house[i].x][house[i].y] = i;
                    break;
                }
            }
        }

        while (true)
        {
            for (int i = 0; i < W + K; i++)
            {
                if (uf.is_water[i] && goal_list[i] == -1)
                {
                    continue;
                }

                if (uf.root(i) != i)
                {
                    // 既に繋がっている
                    continue;
                }
                else
                {
                    if (goal_list[i] == -1)
                    {
                        goal_list[i] = search_goal(i);
                        pair<Position, Position> p;

                        if (uf.is_water[goal_list[i]])
                        {
                            goal_list[goal_list[i]] = i;
                            p = search_start_goal(goal_list[i], i);
                            pos_list[goal_list[i]] = p.first;
                        }

                        p = search_start_goal(i, goal_list[i]);
                        now = p.first;
                        goal_pos = p.second;
                    }
                    else
                    {
                        pair<Position, Position> p;
                        p = search_start_goal(i, goal_list[i]);
                        now = p.first;
                        // now = decesion_move_positon(now, annealing_list[i]);
                        goal_pos = p.second;
                    }

                    // pair<Position, Position> p = search_start_goal(i, goal_list[i]);

                    // now = pos_list[i];
                    // goal_pos = p.second;

                    priority_queue<
                        pair<ll, Position>,
                        vector<pair<ll, Position>>,
                        greater<pair<ll, Position>>>
                        q;
                    q.push({calc_manhattan_dist(now, goal_pos), now});
                    Position next_direction = decesion_next_direction();

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
                        // cout << "a" << endl;
                    }
                    else
                    {
                        bool connect_flag = false;
                        bool continue_flag = true;

                        for (int j = 1; j <= L; j++)
                        {
                            Position next = now + next_direction * j;
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
                                        field[next.x][next.y] = i;
                                        location_list[i].push_back(next);
                                        continue_flag &= annealing_list[i].is_move(sturdiness[now.x][now.y], sturdiness[next.x][next.y]);
                                        z++;
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                sturdiness[next.x][next.y] = sturdiness[next.x - next_direction.x][next.y - next_direction.y];
                            }

                            connect_flag = is_connect(next, i);

                            if (connect_flag)
                            {
                                break;
                            }
                        }

                        if (connect_flag)
                        {
                            cout << "next" << endl;
                            // update_water();
                            break;
                        }

                        for (int j = L; j <= L; j++)
                        {
                            Position next = now + next_direction * j;
                            if (is_excavated[next.x][next.y] &&
                                annealing_list[i].is_move(sturdiness[now.x][now.y], sturdiness[next.x][next.y]))
                            {
                                now = next;
                                pos_list[i] = now;
                                start_position_list[i].push_back(now);
                                q.push({calc_manhattan_dist(now, goal_pos), now});
                            }
                            else
                            {
                                break;
                            }
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
                    cout << z << endl;

                    return;
                }
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

    bool is_connect(Position p, int index)
    {
        bool flag = false;
        int root;
        int child;
        if (field[p.x][p.y] != -1)
        {
            flag = uf.unite(field[p.x][p.y], index);
            if (flag)
            {
                root = uf.root(index);
                if (field[p.x][p.y] == root)
                {
                    child = index;
                }
                else
                {
                    child = field[p.x][p.y];
                }
            }
        }

        for (int j = 0; j < v.size(); j++)
        {
            if (!is_region(p + v[j]))
            {
                continue;
            }

            if (flag)
            {
                break;
            }

            Position _p = p + v[j];
            if (field[_p.x][_p.y] != -1)
            {
                flag = uf.unite(field[_p.x][_p.y], index);
                if (flag)
                {
                    cout << field[_p.x][_p.y] << " " << index << endl;
                    root = uf.root(index);
                    if (field[_p.x][_p.y] == root)
                    {
                        child = index;
                    }
                    else
                    {
                        child = field[_p.x][_p.y];
                    }
                }
            }
        }

        if (flag)
        {

            cout << start_position_list[root].size() << endl;

            location_list[root].insert(
                location_list[root].end(),
                location_list[child].begin(),
                location_list[child].end());
            start_position_list[root].insert(
                start_position_list[root].end(),
                start_position_list[child].begin(),
                start_position_list[child].end());
            cout << start_position_list[root].size() << endl;

            goal_list[root] = -1;
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

    ll calc_dist(int a, int b)
    {
        ll dist = INF;
        for (auto &&i : start_position_list[a])
        {
            for (auto &&j : location_list[b])
            {
                if (chmin(dist, calc_manhattan_dist(i, j)))
                {
                }
            }
        }

        return dist;
    }

    int search_house(int x)
    {
        ll dist = INF;
        int res = 0;

        for (int i = W; i < W + K; i++)
        {
            if (uf.same(x, i))
            {
                continue;
            }

            if (uf.root(i) != i)
            {
                continue;
            }

            if (chmin(dist, calc_dist(x, i)))
            {
                res = i;
            }
        }

        return res;
    }

    int search_house_from_house(int x)
    {
        ll dist = INF;
        int res = 0;

        for (int i = W; i < W + K; i++)
        {
            if (i == x)
            {
                continue;
            }

            if (uf.same(x, i))
            {
                continue;
            }

            if (uf.root(i) != i)
            {
                continue;
            }

            if (chmin(dist, calc_dist(x, i)))
            {
                res = i;
            }
        }

        return res;
    }

    int search_water(int x)
    {
        ll dist = INF;
        int res = 0;

        for (int i = 0; i < water.size(); i++)
        {
            if (uf.same(x, i))
            {
                continue;
            }

            if (uf.root(i) != i)
            {
                continue;
            }

            if (chmin(dist, calc_dist(x, i)))
            {
                res = i;
            }
        }

        return res;
    }

    int search_next_house()
    {
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
        for (int i = W; i < W + K; i++)
        {
            if (!is_water[house[i].x][house[i].y])
            {
                // 家iから最も近い水源の距離
                ll d = calc_manhattan_dist(house[i], water[search_water(i)]);
                q.push({d, i});
            }
        }

        goal_pos = house[q.top().second];

        return q.top().second;
    }

    int search_goal(int index)
    {
        int res;
        if (index < W)
        {
            // 水源indexから最も近い家を返す
            res = search_house(index);
        }
        else
        {
            // 家indexから最も近い家または水源を返す
            int w = search_water(index);
            int h = search_house_from_house(index);
            if (calc_dist(index, w) < calc_dist(index, h))
            {
                res = w;
            }
            else
            {
                res = h;
            }
        }

        return res;
    }

    pair<Position, Position> search_start_goal(int start_i, int goal_i)
    {
        pair<Position, Position> res; // fisrtがstart,secondがgoal
        ll dist = INF;
        for (auto &&i : start_position_list[start_i])
        {
            for (auto &&j : location_list[goal_i])
            {
                if (chmin(dist, calc_manhattan_dist(i, j)))
                {
                    res.first = i;
                    res.second = j;
                }
            }
        }

        return res;
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

    Position decesion_move_positon(Position pos, Annealing annealing)
    {
        Position res;
        ll dist = INF;
        vector<vector<bool>> searched(N, vector<bool>(N, false));

        queue<Position> q;
        q.push(pos);

        while (q.size())
        {
            Position p = q.front();
            q.pop();
            searched[p.x][p.y] = true;

            if (chmin(dist, calc_manhattan_dist(p, goal_pos)))
            {
                res = p;
            }

            for (int i = 0; i < v.size(); i++)
            {
                Position next = p + v[i];
                if (!is_region(next))
                {
                    continue;
                }
                if (searched[next.x][next.y])
                {
                    continue;
                }

                if (sturdiness[next.x][next.y] <= 0 || !is_excavated[next.x][next.y])
                {
                    continue;
                }

                if (annealing.is_move(sturdiness[p.x][p.y], sturdiness[next.x][next.y]))
                {
                    q.push(next);
                }
            }
        }

        return res;
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