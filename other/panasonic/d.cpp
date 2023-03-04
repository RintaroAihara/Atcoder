#include <cstdio>
#include <cstring>
#include <string>
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

ll n;
set<string> ans;

void dfs(string s, char m)
{
    if (s.size() == n)
    {
        ans.insert(s);
        return;
    }

    for (char c = 'a'; c <= m; c++)
    {
        s.push_back(c);
        dfs(s, (c == m) ? m + 1 : m);
        s.pop_back();
    }
}

int main(void)
{
    cin >> n;

    string s;

    dfs(s, 'a');

    for (auto x : ans)
    {
        cout << x << endl;
    }
}