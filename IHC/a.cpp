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
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

ll d;
vector<ll> c(26 + 1, 0);
vector<vector<ll>> s(365 + 1, vector<ll>(26 + 1, 0));

ll scoring(vector<int> t)
{
    ll ans = 0;
    vector<ll> last(26 + 1, 0);

    for (int i = 1; i <= d; i++)
    {
        ans += s[i][t[i]];
        ans -= c[t[i]] * (i - last[t[i]]) * (i - last[t[i]] - 1) / 2;
        last[t[i]] = i;
    }

    for (int i = 1; i <= 26; i++)
    {

        ans -= c[i] * (d - last[i] + 1) * (d - last[i]) / 2;
    }

    return ans;
}

int main(void)
{
    random_device seed_gen;
    mt19937 rand(seed_gen());
    cin >> d;

    for (int i = 1; i <= 26; i++)
    {
        cin >> c[i];
    }

    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= 26; j++)
        {
            cin >> s[i][j];
        }
    }

    vector<int> BestT(d + 1, 1);

    for (int i = 1; i <= d; i++)
    {
        BestT[i] = rand() % 26 + 1;
    }

    double BestScore = scoring(BestT);
    double score;

    auto start = chrono::system_clock::now();
    vector<int> t(d + 1, 1);

    double T0 = 1e6;
    double T1 = 5e2;
    double TL = 1980;
    double msec;

    ll count = 0;

    while (1)
    {
        if (count % 100 == 0)
        {
            msec = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count();
        }

        if (msec >= TL)
        {
            break;
        }

        double T = powf(T0, 1 - msec / TL) * powf(T1, msec / TL);

        t = BestT;

        for (int i = 0; i < 3; i++)
        {
            t[rand() % d + 1] = rand() % 26 + 1;
        }

        score = scoring(t);

        double p = exp((score - BestScore) / T);

        if (p > 0.5)
        {
            BestT = t;
            BestScore = score;
        }

        count++;
    }

    for (int i = 1; i <= d; i++)
    {
        printf("%d\n", BestT[i]);
    }
}
