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

    Position now;

    map<int, vector<Position>> water_to_house;

    chrono::system_clock::time_point start, end;

    Optimizer()
    {
        P = 100;
        input();
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
        opt.now = opt.water[i];
        for (auto &goal : opt.water_to_house[i])
        {
            while (true)
            {
                while (true)
                {
                    opt.excavation();

                    int r;
                    cin >> r;

                    if (r == 2 || r == -1)
                    {
                        return 0;
                    }
                    else if (r == 1)
                    {
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