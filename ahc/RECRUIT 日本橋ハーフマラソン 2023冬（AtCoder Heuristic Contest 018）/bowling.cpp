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
        if (filename == "")
        {
            return;
        }

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

    void step()
    {
        time += 1;
        // cout << "time:" << time << endl;
    }

    bool is_move(int score)
    {
        return score <= 500 + time * 100;
    }
};

class Agent
{
public:
    int self_i, goal_i;
    Position now;
    Position start;
    Position goal;
    vector<Position> location_list;
    vector<Position> start_position_list;
    vector<int> direction;
    Annealing annealing;

    vector<Position> v = {
        Position{1, 0},
        Position{-1, 0},
        Position{0, 1},
        Position{0, -1},
    };

    Agent(){};
    Agent(int index, Position s, Annealing a)
    {
        self_i = index;
        goal_i = -1;
        start = s;
        location_list.push_back(start);
        start_position_list.push_back(start);
        annealing = a;
    };

    void set_goal(int goal_index, Position g)
    {
        goal_i = goal_index;
        goal = g;
        direction = decision_direction();
    }

    ll manhattan(Position a, Position b)
    {
        return abs(a.x - b.x) + abs(a.y - b.y);
    }

    vector<int> decision_direction()
    {
        Position direction = goal - start;
        vector<int> res;

        vector<pair<ll, ll>> scorelist;

        for (int i = 0; i < v.size(); i++)
        {
            Position next = start + v[i];
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

        for (int i = 0; i < 3; i++)
        {
            res.push_back(scorelist[i].second);
        }

        return res;
    }

    void move(Position next, bool is_excavated, int score)
    {
        if (is_excavated && annealing.is_move(score))
        {
            start_position_list.push_back(next);
        }
    }
};

class Dijkstra
{
private:
    ll n; // 頂点数

    struct edge
    {
        ll to;
        ll cost;
    };

public:
    vector<vector<edge>> G; // 隣接リスト
    vector<ll> distance;
    vector<vector<ll>> route;

    Dijkstra(ll n) : n(n)
    {
        G.assign(n, vector<edge>());
        route.assign(n, vector<ll>());
    }

    void dijkstra(int s)
    {
        priority_queue<P, vector<P>, greater<P>> q;
        distance.assign(n, INF);
        distance[s] = 0;
        q.emplace(0, s);

        while (q.size())
        {
            P p = q.top();
            q.pop();
            int v = p.second;

            if (distance[v] < p.first)
            {
                continue;
            }

            for (auto &x : G[v])
            {
                edge e = x;

                if (distance[e.to] > distance[v] + e.cost)
                {
                    route[e.to] = route[v];
                    route[e.to].push_back(v);
                    distance[e.to] = distance[v] + e.cost;
                    q.emplace(distance[e.to], e.to);
                }
            }
        }
    }
};

class Optimizer
{
public:
    ll N, W, K, C, P, L, B;

    vector<Position> water;
    vector<Position> house;
    vector<Position> v = {
        Position{1, 0},
        Position{-1, 0},
        Position{0, 1},
        Position{0, -1},
    };
    vector<vector<bool>> is_excavated;
    vector<vector<bool>> reached;
    vector<vector<int>> sturdiness;
    vector<vector<int>> field;
    vector<Agent> agent;

    unionfind uf;

    Position now;
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
        B = 3;
        // cout << "start" << endl;

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
            house.resize(W);
            is_excavated.assign(N, vector<bool>(N, false));
            reached.assign(N, vector<bool>(N, false));
            sturdiness.assign(N, vector<int>(N, 0));
            field.assign(N, vector<int>(N, -1));
            agent.resize(W + K);
            water = _test.water;
            house = _test.house;
            test = _test;

            for (int i = 0; i < W; i++)
            {
                field[water[i].x][water[i].y] = i;
                agent[i] = Agent(i, water[i], Annealing(P, L));
            }

            for (int i = W; i < W + K; i++)
            {
                field[house[i].x][house[i].y] = i;
                agent[i] = Agent(i, house[i], Annealing(P, L));
            }

            ofs.open(test.output, std::ios::out);
        }

        P = plist[C];
        L = l;
    };

    void init()
    {
    }

    void input()
    {
        cin >> N >> W >> K >> C;

        uf.init(W, K);
        house.resize(W);
        is_excavated.assign(N, vector<bool>(N, false));
        reached.assign(N, vector<bool>(N, false));
        sturdiness.assign(N, vector<int>(N, 0));
        field.assign(N, vector<int>(N, -1));
        agent.resize(W + K);

        for (int i = 0; i < W; i++)
        {
            int a, b;
            cin >> a >> b;
            water.push_back(Position{a, b});
            agent[i] = Agent(i, water[i], Annealing(P, L));
            field[a][b] = i;
        }

        for (int i = W; i < W + K; i++)
        {
            int c, d;
            cin >> c >> d;
            house.push_back(Position{c, d});
            agent[i] = Agent(i, house[i], Annealing(P, L));
            field[c][d] = i;
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
                    reached[water[i].x][water[i].y] = true;
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
                    reached[house[i].x][house[i].y] = true;
                    break;
                }
            }
        }

        while (true)
        {
            for (int i = 0; i < W + K; i++)
            {
                end = chrono::system_clock::now();
                if (chrono::duration_cast<chrono::milliseconds>(end - start).count() >= 4900)
                {
                    return;
                }

                if (uf.is_water[i] && agent[i].goal_i == -1)
                {
                    continue;
                }

                if (uf.root(i) != i)
                {
                    // 既に繋がっている
                    continue;
                }

                if (agent[i].goal_i == -1)
                {
                    agent[i].annealing.init();
                    agent[i].start_position_list = make_start_list(i);

                    agent[i].goal_i = search_goal(i);
                    pair<Position, Position> p;

                    if (uf.is_water[agent[i].goal_i])
                    {
                        int goal_i = uf.root(agent[i].goal_i);
                        agent[goal_i].goal_i = i;
                    }

                    p = search_start_goal(i, agent[i].goal_i);

                    goal_pos = p.second;
                    cout << i << " " << goal_pos.x << " " << goal_pos.y << endl;
                    for (auto &&j : agent)
                    {
                        cout << j.goal_i << " ";
                    }

                    cout << endl;
                    now = decesion_move_positon(i, agent[i].goal_i);
                    agent[i].set_goal(agent[i].goal_i, goal_pos);
                }
                else
                {
                    pair<Position, Position> p;
                    agent[i].goal_i = uf.root(agent[i].goal_i);
                    p = search_start_goal(i, agent[i].goal_i);
                    goal_pos = p.second;
                    agent[i].set_goal(agent[i].goal_i, goal_pos);
                    now = decesion_move_positon(i, agent[i].goal_i);
                }

                Position next_direction = decesion_next_direction(now, goal_pos);

                if (next_direction == Position{-1, -1})
                {
                    agent[i].annealing.step();
                }
                else
                {
                    bool connect_flag = false;

                    Position next = now + next_direction * L;
                    if (!is_excavated[next.x][next.y])
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
                                agent[i].location_list.push_back(next);
                                z++;
                                break;
                            }
                        }
                    }

                    connect_flag = is_connect(next, i);

                    if (connect_flag)
                    {
                        continue;
                    }

                    // agent[i].move(
                    //     next, is_excavated[next.x][next.y], sturdiness[next.x][next.y]);
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

        for (int i = 0; i <= L; i++)
        {
            for (int j = 0; j <= L; j++)
            {
                for (auto &&v1 : v)
                {
                    for (auto &&v2 : v)
                    {
                        if (v1 == v2)
                        {
                            continue;
                        }

                        Position _p = p + v1 * i + v2 * j;

                        if (!is_region(_p))
                        {
                            continue;
                        }

                        if (flag)
                        {
                            break;
                        }

                        if (field[_p.x][_p.y] != -1)
                        {
                            flag = uf.unite(field[_p.x][_p.y], index);
                            if (flag)
                            {
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

                        if (flag)
                        {
                            agent[root].location_list.insert(
                                agent[root].location_list.end(),
                                agent[child].location_list.begin(),
                                agent[child].location_list.end());
                            agent[root].start_position_list.insert(
                                agent[root].start_position_list.end(),
                                agent[child].start_position_list.begin(),
                                agent[child].start_position_list.end());

                            connect(root, child);

                            agent[root].goal_i = -1;

                            return flag;
                        }
                    }
                }
            }
        }

        return flag;
    }

    void connect(int start_i, int goal_i)
    {
        vector<vector<ll>> position_to_index(N, vector<ll>(N, -1));

        for (int i = 0; i < agent[start_i].location_list.size(); i++)
        {
            position_to_index[agent[start_i].location_list[i].x][agent[start_i].location_list[i].y] = i;
        }

        Dijkstra d(agent[start_i].location_list.size());

        for (auto &&i : agent[start_i].location_list)
        {
            for (auto &&j : agent[start_i].location_list)
            {
                if (i == j)
                {
                    continue;
                }

                if (abs(i.x - j.x) <= L && abs(i.y - j.y) <= L)
                {
                    ll cost = (manhattan(i, j) - 1) * sturdiness[j.x][j.y];
                    d.G[position_to_index[i.x][i.y]].push_back({position_to_index[j.x][j.y], cost});
                }
            }
        }

        d.dijkstra(position_to_index[agent[start_i].start.x][agent[start_i].start.y]);

        vector<ll> route = d.route[position_to_index[agent[goal_i].start.x][agent[goal_i].start.y]];
        route.push_back(position_to_index[agent[goal_i].start.x][agent[goal_i].start.y]);
        for (int i = 0; i < route.size() - 1; i++)
        {
            Position a = agent[start_i].location_list[route[i]];
            Position b = agent[start_i].location_list[route[i + 1]];

            Position next = a;
            for (int j = 0; j < abs(b.x - a.x); j++)
            {
                Position direction = {(b.x - a.x) / abs(b.x - a.x), 0};
                next = next + direction;
                if (is_excavated[next.x][next.y])
                {
                    continue;
                }

                while (true)
                {
                    int r = ask(next);

                    if (r == 2 || r == -1)
                    {
                        return;
                    }
                    else if (r == 1)
                    {
                        field[next.x][next.y] = start_i;
                        agent[start_i].location_list.push_back(next);
                        break;
                    }
                }
            }

            for (int j = 0; j < abs(b.y - a.y); j++)
            {
                Position direction = {0, (b.y - a.y) / abs(b.y - a.y)};
                next = next + direction;
                if (is_excavated[next.x][next.y])
                {
                    continue;
                }

                while (true)
                {
                    int r = ask(next);
                    if (r == 2 || r == -1)
                    {
                        return;
                    }
                    else if (r == 1)
                    {
                        field[next.x][next.y] = start_i;
                        agent[start_i].location_list.push_back(next);
                        break;
                    }
                }
            }
        }
    }

    vector<Position> make_start_list(int index)
    {
        queue<Position> q;
        q.push(agent[index].start);
        vector<vector<bool>> searched(N, vector<bool>(N, false));
        vector<Position> res;

        while (q.size())
        {
            Position p = q.front();
            q.pop();
            res.push_back(p);
            searched[p.x][p.y] = true;

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

                if (is_excavated[next.x][next.y])
                {
                    q.push(next);
                }
            }
        }

        return res;
    }

    ll manhattan(Position a, Position b)
    {
        return abs(a.x - b.x) + abs(a.y - b.y);
    }

    ll calc_dist(int a, int b)
    {
        ll dist = INF;
        for (auto &&i : agent[a].start_position_list)
        {
            for (auto &&j : agent[b].location_list)
            {
                if (chmin(dist, manhattan(i, j)))
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

        for (int i = 0; i < W; i++)
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

        return uf.root(res);
    }

    pair<Position, Position> search_start_goal(int start_i, int goal_i)
    {
        pair<Position, Position> res; // fisrtがstart,secondがgoal
        ll dist = INF;
        for (auto &&i : agent[start_i].start_position_list)
        {
            for (auto &&j : agent[goal_i].location_list)
            {
                if (chmin(dist, manhattan(i, j)))
                {
                    res.first = i;
                    res.second = j;
                }
            }
        }

        return res;
    }

    Position decesion_next_direction(Position pos, Position goal)
    {
        Position direction = goal - pos;
        ll bestscore = 0;
        ll best_i = 0;

        vector<pair<ll, ll>> scorelist;

        for (int i = 0; i < v.size(); i++)
        {
            Position next = pos + v[i] * L;

            if (!is_region(next))
            {
                continue;
            }

            bool flag = false;

            for (int j = next.x - (L - 1); j <= next.x + (L - 1); j++)
            {
                for (int k = next.y - (L - 1); k <= next.y + (L - 1); k++)
                {
                    if (!is_region(Position{j, k}))
                    {
                        continue;
                    }

                    if (uf.same(field[pos.x][pos.y], field[j][k]))
                    {
                        flag = true;
                    }
                }
            }

            if (flag)
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

        if (scorelist.size() >= 2)
        {
            sort(scorelist.begin(), scorelist.end(), greater<pair<ll, ll>>());

            return v[scorelist[0].second];
        }
        else
        {
            return Position{-1, -1};
        }
    }

    Position decesion_move_positon(int start_i, int goal_i)
    {
        Position res = Position{-1, -1};
        ll cost = INF;

        for (auto &&i : agent[start_i].location_list)
        {
            for (auto &&j : agent[goal_i].location_list)
            {
                ll _cost = manhattan(i, j) * manhattan(i, j) * (sturdiness[i.x][i.y] + sturdiness[j.x][j.y]) / 2;
                if (decesion_next_direction(i, j) == Position{-1, -1})
                {
                    continue;
                }

                if (chmin(cost, _cost))
                {
                    res = i;
                }
            }
        }

        return res;
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
    Mode mode;
    Test test("", "output.txt");

    if (argc == 1)
    {
        mode = Mode::Real;
    }
    else
    {
        mode = Mode::Test;
        test = Test(argv[1], "output.txt");
    }

    Optimizer opt(test, mode, 3);
    opt.solve();
}