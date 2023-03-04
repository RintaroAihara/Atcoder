#include <cstdio>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1e18) + 1;

int main(void)
{
    int n, d, a;
    vector<P> monster;
    int x, h;
    int i, j;
    int tx, th;
    int mid;
    ll count;
    ll ans = 0;
    queue<P> bomb; //位置、ダメージ
    ll damage = 0;

    cin >> n >> d >> a;

    monster.emplace_back(0, 0);

    rep(i, 1, n + 1)
    {
        cin >> x >> h;
        monster.emplace_back(x, h);
    }

    sort(monster.begin(), monster.end());

    rep(i, 1, n + 1)
    {
        tx = monster[i].first;
        th = monster[i].second;

        while (bomb.size() && monster[i].first > bomb.front().first + d * 2)
        {
            damage -= bomb.front().second;
            bomb.pop();
        }

        if (th - damage > 0)
        {
            th -= damage;
            
            count = (th + a - 1) / a;

            bomb.push(P(tx, count * a));

            damage += count * a;

            ans += count;
        }
    }

    cout << ans << endl;
}