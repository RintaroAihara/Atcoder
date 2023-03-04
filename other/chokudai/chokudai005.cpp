#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <tuple>
#include <numeric>
#include <random>
#include <chrono>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using namespace chrono;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int id, n, k;
vector<string> s;

ll evaluate(int q, vector<int> y, vector<int> x, vector<char> c)
{
    ll score = 0;
    map<char, ll> m;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            m[s[i][j]]++;
        }
    }

    for (int i = 0; i < q; i++)
    {
        queue<P> que;
        que.push({y[i], x[i]});
        char a = s[y[i]][x[i]];

        while (que.size())
        {
            P p = que.front();
            que.pop();
            m[s[p.first][p.second]]--;

            s[p.first][p.second] = c[i];
            m[s[p.first][p.second]]++;

            for (int j = 0; j < 4; j++)
            {
                int ny = p.first + dy[j], nx = p.second + dx[j];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                {
                    continue;
                }

                if (s[ny][nx] != a)
                {
                    continue;
                }

                que.push({ny, nx});
            }
        }
    }

    ll tmp = 0;

    for (auto &&i : m)
    {
        tmp = max(tmp, i.second);
    }

    score = tmp * 100 - q;

    return score;
}

int main(void)
{
    cin >> id >> n >> k;

    random_device seed_gen;
    uniform_int_distribution<> rand(0, n - 1);
    uniform_int_distribution<> ch(1, k);

    s.assign(n, string());

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    vector<int> y, x;

    vector<char> c;

    auto start = system_clock::now();
    double msec;
    double TL = 2900;

    ll q = 0;

    while (true)
    {
        vector<int> y2, x2;
        vector<char> c2;
        ll q2;
        ll bestscore = 0;

        msec = duration_cast<milliseconds>(system_clock::now() - start).count();

        if (msec >= TL)
        {
            break;
        }

        for (int i = 1; i <= 100; i++)
        {
            bool flag = true;
            for (int j = 0; j < 10; j++)
            {
                y2.push_back(rand(seed_gen));
                x2.push_back(rand(seed_gen));
                c2.push_back(char('0' + ch(seed_gen)));

                ll score = evaluate(i, y2, x2, c2);

                if (bestscore < score)
                {
                    bestscore = score;
                    flag = false;
                    q2 = i;
                    break;
                }

                y2.pop_back();
                x2.pop_back();
                c2.pop_back();
            }

            if (flag)
            {
                break;
            }
        }

        if (evaluate(q, y, x, c) < evaluate(q2, y2, x2, c2))
        {
            q = q2;
            y = y2;
            x = x2;
            c = c2;
        }
    }

    cout << q << endl;

    for (int i = 0; i < q; i++)
    {
        printf("%d %d %c\n", y[i], x[i], c[i]);
    }
}