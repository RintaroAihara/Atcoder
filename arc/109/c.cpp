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

int n, k;

vector<vector<char>> memo;

ll power(ll x, ll y)
{
    ll ans = 1;
    while (y)
    {
        if (y & 1)
            ans = (ans * x) % n;
        x = (x * x) % n;
        y >>= 1;
    }
    return ans;
}

char winner(char l, char r)
{
    if (l > r)
    {
        swap(l, r);
    }

    char res;

    if (l == r)
    {
        res = l;
    }
    else if (l == 'P' && r == 'R')
    {
        res = 'P';
    }
    else if (l == 'R' && r == 'S')
    {
        res = 'R';
    }
    else
    {
        res = 'S';
    }

    return res;
}

char dp(int x, int k)
{
    if (memo[x][k] != '0')
    {
        return memo[x][k];
    }

    char l, r;
    l = dp(x, k - 1);
    r = dp((x + power(2, k - 1)) % n, k - 1);

    return memo[x][k] = winner(l, r);
}

int main(void)
{
    cin >> n >> k;
    string s;
    cin >> s;

    memo.assign(n, vector<char>(k + 1, '0'));

    for (int i = 0; i < n; i++)
    {
        memo[i][0] = s[i];
    }

    cout << dp(0, k) << endl;
}