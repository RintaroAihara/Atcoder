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

    Position nearhouse;
    Position now;

    Optimizer()
    {
        Position nearhouse = {0, 0};
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

        for (int i = 0; i < W; i++)
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

    void search_nearhouse(Position w)
    {
        ll dist = INF;

        for (auto &&i : house)
        {
            if (chmin(dist, calc_manhattan_dist(w, i)))
            {
                nearhouse = i;
            }
        }
    }

    void move()
    {
        if (abs(nearhouse.x - now.x) > 0)
        {
            now.x += (nearhouse.x - now.x) / abs(nearhouse.x - now.x);
        }
        else if (abs(nearhouse.y - now.y) > 0)
        {
            now.y += (nearhouse.y - now.y) / abs(nearhouse.y - now.y);
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

    for (int i = 0; i < opt.water.size(); i++)
    {
        opt.now = opt.water[i];
        opt.search_nearhouse(opt.water[i]);
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
            opt.move();

            end = chrono::system_clock::now();
            if (chrono::duration_cast<chrono::milliseconds>(end - start).count() >= 4900)
            {
                return 0;
            }
        }
    }
}