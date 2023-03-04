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

template <class T>
class Roullette
{
public:
    vector<T> itemlist;
    vector<int> scorelist;
    Roullette(){

    };

    T choice()
    {
        int sum = 0;
        for (auto &&score : scorelist)
        {
            sum += score;
        }
    }

    void add(int score, T item)
    {
        scorelist.push_back(score);
        itemlist.push_back(item);
    }
};

class Optimizer
{
public:
    ll N, W, K, C, P;

    vector<Position> water;
    vector<Position> house;
    vector<Position> v = {
        Position{1, 0},
        Position{-1, 0},
        Position{0, 1},
        Position{0, -1},
    };
    vector<vector<bool>> is_bedrock, searched, is_water;
    vector<vector<int>> sturdiness;

    Position now;
    Position now_vector;
    Position next;
    Position goal_house;

    int pred_s = 0;

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

    chrono::system_clock::time_point start, end;

    Optimizer()
    {
        input();
        P = plist[C];
        now_vector = {0, 0};
    };

    void input()
    {
        cin >> N >> W >> K >> C;
        is_bedrock.assign(N, vector<bool>(N, false));
        is_water.assign(N, vector<bool>(N, false));
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

    void set_now(Position a)
    {
        now = a;
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

                if (is_bedrock[nx][ny])
                {
                    water.push_back(Position{nx, ny});
                    is_water[nx][ny] = true;
                    q.push(Position{nx, ny});
                }
            }
        }
    }

    bool predict_sturdiness()
    {
        // 岩盤の頑丈さを予測
        int prev, prev2;
        if (is_region(now - now_vector))
        {
            prev = sturdiness[now.x - now_vector.x][now.y - now_vector.y];
        }
        else
        {
            return false;
        }

        if (is_region(now - now_vector * 2))
        {
            prev2 = sturdiness[now.x - now_vector.x * 2][now.y - now_vector.y * 2];
        }
        else
        {
            return false;
        }

        if (prev > 0 && prev2 > 0)
        {
            pred_s = prev + (prev - prev2);
            return true;
        }
        else
        {
            return false;
        }
    }

    void move()
    {
        now = next;
    }

    ll evaluate(Position next)
    {
        ll a = 100; // a:dの係数
        ll b = 1;   // b:sの係数
        ll d = calc_manhattan_dist(next, goal_house) - calc_manhattan_dist(now, goal_house);
        ll s = sturdiness[next.x][next.y] - sturdiness[now.x][now.y];

        return a * d + b * s;
    }

    void excavation()
    {
        ll score = 0;
        ll best_i = 0;
        for (int i = 0; i < v.size(); i++)
        {
            next = now + v[i];

            if (is_bedrock[next.x][next.y] || !is_region(next))
            {
                continue;
            }

            if (chmax(score, evaluate(now + v[i])))
            {
                best_i = i;
            }
        }
        next = now + v[best_i];
        sturdiness[next.x][next.y] += P;
        cout << next.x << " " << next.y << " " << P << endl;
    }

    void water_excavation()
    {
        sturdiness[now.x][now.y] += P;
        cout << now.x << " " << now.y << " " << P << endl;
    }

    void step()
    {
        update_water();
        P = plist[C];
    }
};

int main(void)
{
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();

    Optimizer opt;
    while (true)
    {
        int i = opt.search_next_house();
        opt.now = opt.water[opt.search_nearwater(i)];
        while (true)
        {
            while (true)
            {
                if (opt.is_bedrock[opt.now.x][opt.now.y])
                {
                    break;
                }

                if (opt.is_water[opt.now.x][opt.now.y] && opt.is_bedrock[opt.now.x][opt.now.y])
                {
                    opt.water_excavation();
                }
                else
                {
                    opt.excavation();
                }

                int r;
                cin >> r;

                if (r == 2 || r == -1)
                {
                    return 0;
                }
                else if (r == 1)
                {
                    opt.is_bedrock[opt.now.x][opt.now.y] = true;
                    break;
                }

                end = chrono::system_clock::now();
                if (chrono::duration_cast<chrono::milliseconds>(end - start).count() >= 4900)
                {
                    return 0;
                }
            }

            if (opt.now == opt.goal_house)
            {
                opt.step();
                break;
            }

            opt.move();

            end = chrono::system_clock::now();
            if (chrono::duration_cast<chrono::milliseconds>(end - start).count() >= 4900)
            {
                return 0;
            }
        }
    }
}