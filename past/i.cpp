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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    ll n, q;
    cin >> n >> q;

    vector<ll> row(n + 3, 0), column(n + 3, 0);

    for (int i = 1; i <= n; i++)
    {
        row[i] = i;
        column[i] = i;
    }

    bool flag = true;
    vector<ll> ans;

    for (int i = 0; i < q; i++)
    {
        int p;
        cin >> p;

        switch (p)
        {
            int a, b;
        case 1:
            cin >> a >> b;
            if (flag)
            {
                swap(row[a], row[b]);
            }
            else
            {
                swap(column[a], column[b]);
            }

            break;

        case 2:
            cin >> a >> b;
            if (flag)
            {
                swap(column[a], column[b]);
            }
            else
            {
                swap(row[a], row[b]);
            }
            break;

        case 3:
            flag = !flag;
            break;

        case 4:
            cin >> a >> b;

            if (flag)
            {
                ans.push_back(n * (row[a] - 1) + column[b] - 1);
            }
            else
            {
                ans.push_back(n * (row[b] - 1) + column[a] - 1);
            }
            break;
        }
    }

    for (auto p : ans)
    {
        cout << p << endl;
    }
}
