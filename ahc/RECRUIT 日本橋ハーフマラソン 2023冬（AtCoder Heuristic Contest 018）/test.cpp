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
    ll x;
    ll y;

    bool operator==(Position a)
    {
        return (x == a.x) && (y == a.y);
    }

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
class Test
{
public:
    ll N, W, K, C, P;
    string output;
    vector<Position> water;
    vector<Position> house;
    vector<vector<int>> is_excavated;
    vector<vector<bool>> is_house, is_water;

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

    bool same(long long x, long long y)
    {
        return root(x) == root(y);
    }

public:
    map<int, bool> is_water;

    void init(ll w, ll k)
    {
        d.assign(w + k, -1);

        for (int i = 0; i < w; i++)
        {
            is_water[i] = true;
        }
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

        is_water[x] |= is_water[y];
        is_water[y] |= is_water[x];

        d[x] += d[y];
        d[y] = x;
        return true;
    }

    long long size(long long x)
    {
        return -d[root(x)];
    }
};

class Optimizer
{
public:
    ll N, W, K, C, P, L;

    vector<vector<Position>> location;
    unionfind uf;

    vector<Position> water;
    vector<Position> house;
    vector<Position> v = {
        Position{1, 0},
        Position{-1, 0},
        Position{0, 1},
        Position{0, -1},
    };
    vector<vector<bool>> is_excavated, searched, is_water;
    vector<vector<int>> sturdiness;

    Position parent;
    Position child;
    Position now_vector;
    Position next;
    Position goal_house;

    int step = 0;

    map<int, vector<Position>> water_to_house;
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

    Optimizer(Test test, int l)
    {
        N = test.N;
        W = test.W;
        K = test.K;
        C = test.C;
        is_water.assign(N, vector<bool>(N, false));
        sturdiness.assign(N, vector<int>(N, 0));
        location.assign(W + K, vector<Position>());
        uf.init(W, K);
        water = test.water;
        house = test.house;

        for (int i = 0; i < W; i++)
        {
            location[i].push_back({water[i]});
        }

        for (int i = 0; i < K; i++)
        {
            location[i].push_back({house[i]});
        }

        L = l;

        for (auto &&i : water)
        {
            is_water[i.x][i.y] = true;
        }

        ofs.open(test.output, std::ios::out);
        // input();
        P = plist[C];
        is_excavated.assign(N, vector<bool>(N, false));
    };

    void input()
    {
        cin >> N >> W >> K >> C;

        is_water.assign(N, vector<bool>(N, false));

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

        for (int i = 0; i < W; i++)
        {
            location[i].push_back({water[i]});
        }

        for (int i = 0; i < K; i++)
        {
            location[i].push_back({house[i]});
        }
    }

    void solve()
    {
        while (true)
        {
            for (int i = 0; i < W + K; i++)
            {
                if (uf.root(i) != i)
                {
                    continue;
                }

                if (i < W)
                {
                }
                else
                {
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

    ll calc_manhattan_dist(Position a, Position b)
    {
        return abs(a.x - b.x) + abs(a.y - b.y);
    }

    int search_nearhouse(int x)
    {
        ll dist = INF;
        int res = 0;

        for (int i = W; i < W + K; i++)
        {
            for (int j = 0; j < location[i].size(); j++)
            {
                        }
        }

        for (int i = 0; i < house.size(); i++)
        {
            if (uf.is_water[i])
            {
                continue;
            }

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

        goal_house = house[q.top().second];

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

    bool update_parent()
    {
        if (sturdiness[parent.x][parent.y] + P * 6 * (1 + 0.02 * step) >= sturdiness[child.x][child.y])
        {
            parent = child;
            return true;
        }
        else
        {
            child = parent;
            return false;
        }
    }

    Position decesion_direction(int n)
    {
        Position direction = goal_house - child;
        ll bestscore = 0;
        ll best_i = 0;

        vector<pair<ll, ll>> scorelist;

        for (int i = 0; i < v.size(); i++)
        {
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

        return v[scorelist[n].second];
    }

    void move()
    {
        child = next;
    }

    void excavation()
    {
        next = child + now_vector;
        sturdiness[next.x][next.y] = min(P + sturdiness[next.x][next.y], 5000ll);
        cout << next.x << " " << next.y << " " << P << endl;
    }

    void water_excavation()
    {
        sturdiness[child.x][child.y] += P;
        cout << child.x << " " << child.y << " " << P << endl;
    }

    Position _excavation()
    {
        next = child + now_vector;
        sturdiness[next.x][next.y] = min(P + sturdiness[next.x][next.y], 5000ll);
        ofs << next.x << " " << next.y << " " << P << endl;
        return next;
    }

    Position _water_excavation()
    {
        sturdiness[child.x][child.y] += P;
        ofs << child.x << " " << child.y << " " << P << endl;
        return child;
    }
};

int main(int argc, char *argv[])
{
    Test test(argv[1], "output.txt");
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();

    Optimizer opt(test, 3);

    while (true)
    {
        int i = opt.search_next_house();
        opt.parent = opt.water[opt.search_nearwater(i)];
        opt.child = opt.parent;
        opt.next = opt.child;
        cout << opt.goal_house.x << " " << opt.goal_house.y << endl;
        int n = 0;
        opt.step = 0;
        while (true)
        {
            opt.now_vector = opt.decesion_direction(n);
            bool flag = false;
            Position p = opt.child;
            for (int i = 0; i < opt.L; i++)
            {
                p = p + opt.now_vector;
                if (opt.is_excavated[p.x][p.y])
                {
                    flag = true;
                }
            }
            if (flag)
            {
                n++;
                continue;
            }

            for (int i = 0; i < opt.L; i++, opt.step++)
            {
                while (true)
                {
                    int r;
                    if (opt.is_water[opt.child.x][opt.child.y] && !opt.is_excavated[opt.child.x][opt.child.y])
                    {
                        r = test.ask(opt._water_excavation(), opt.P);
                    }
                    else if (opt.is_excavated[opt.child.x + opt.now_vector.x][opt.child.y + opt.now_vector.y])
                    {

                        opt.next = opt.child + opt.now_vector;
                        opt.move();
                        break;
                    }
                    else
                    {
                        r = test.ask(opt._excavation(), opt.P);
                    }
                    // cin >> r;

                    if (r == 2 || r == -1)
                    {
                        return 0;
                    }
                    else if (r == 1)
                    {
                        opt.move();
                        opt.is_excavated[opt.child.x][opt.child.y] = true;
                        break;
                    }

                    end = chrono::system_clock::now();
                    if (chrono::duration_cast<chrono::milliseconds>(end - start).count() >= 4900)
                    {
                        return 0;
                    }
                }
                if (opt.calc_manhattan_dist(opt.goal_house, opt.child) < opt.L * 2)
                {
                    if (abs(opt.now_vector.x) > 0 && opt.child.x == opt.goal_house.x)
                    {
                        break;
                    }

                    if (abs(opt.now_vector.y) > 0 && opt.child.y == opt.goal_house.y)
                    {
                        break;
                    }
                }
            }

            if (opt.update_parent())
            {
                n = 0;
            }
            else
            {
                n++;
            }

            if (opt.is_excavated[opt.goal_house.x][opt.goal_house.y])
            {
                opt.update_water();
                break;
            }

            end = chrono::system_clock::now();
            if (chrono::duration_cast<chrono::milliseconds>(end - start).count() >= 4900)
            {
                return 0;
            }
        }
    }
}