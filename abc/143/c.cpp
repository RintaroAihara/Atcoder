#include <cstdio>
#include <cstring>
#include <cmath>
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
    int n;
    string s;
    int i;
    int ans = 1;

    cin >> n >> s;

    rep(i, 1, n)
    {
        if (s[i] == s[i - 1])
        {
        }
        else
        {
            ans++;
        }
    }

    cout << ans << endl;
}