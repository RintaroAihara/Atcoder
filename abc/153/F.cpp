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
    int target, targetx, targeth;
    int mid;
    ll count;
    ll ans = 0;
    vector<int> damage(200010, 0);

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
        damage[i] += damage[i - 1];

        if (damage[i] < monster[i].second)
        {
            target = i;
        }
        else
        {
            continue;
        }

        targetx = monster[target].first;
        targeth = monster[target].second - damage[target];

        count = (targeth + a - 1) / a;

        ans += count;

        int ok = 0, ng = n + 1;

        while (ng - ok > 1)
        {
            mid = (ok + ng) / 2;

            if (monster[mid].first <= targetx + d * 2)
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }
        damage[target] += count * a;
        damage[ng] += -count * a;
    }

    cout << ans << endl;
}