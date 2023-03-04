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
    string s, t;
    int i;
    int ans = 0;

    cin >> s >> t;

    for (i = 0; i < 3; i++)
    {
        if (s[i] == t[i])
        {
            ans++;
        }
    }

    cout << ans << endl;
}