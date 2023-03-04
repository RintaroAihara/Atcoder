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
#include <stack>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    int n;
    int i;
    int ans = 0;
    int count = 0;
    cin >> n;
    vector<int> h(n);

    for (i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    for (i = 1; i < n; i++)
    {
        if (h[i] <= h[i - 1])
        {
            count++;
            ans = max(count, ans);
        }
        else
        {
            count = 0;
        }
    }

    cout << ans << endl;
}