#include <cstdio>
#include <cstring>
#include <cmath>
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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

ll n, k;
vector<vector<int>> T;
ll ans = 0;

void dfs(vector<int> a)
{
    if (a.size() == n)
    {
        a.push_back(0);

        ll tmp = 0;

        for (int i = 0; i < n; i++)
        {
            tmp += T[a[i]][a[i + 1]];
        }

        if (tmp == k)
        {
            ans++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] == i)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            a.push_back(i);
            dfs(a);
            a.pop_back();
        }
    }
}

int main(void)
{
    cin >> n >> k;

    T.assign(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> T[i][j];
        }
    }

    vector<int> a(1, 0);

    dfs(a);

    cout << ans << endl;
}
