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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    int n, d;
    int ans = 0;

    cin >> n >> d;

    int x[100][100];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cin >> x[i][j];
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = 0;
            for (int k = 0; k < d; k++)
            {
                sum += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
            }

            int s = sqrt(sum);

            if (s * s == sum)
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
}