#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <queue>
#include <stack>
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1e9 + 7;

int main(void)
{
    int n;
    vector<string> s;
    vector<pair<int, string>> ans;
    vector<string> ans2;
    int i;

    cin >> n;

    s.resize(n);

    rep(i, 0, n)
    {
        cin >> s[i];
    }

    sort(s.begin(), s.end());

    ans.push_back(make_pair(0, s.front()));

    rep(i, 1, n)
    {
        if (ans.back().second == s[i])
        {
            ans.back().first++;
        }
        else
        {
            ans.push_back(make_pair(0, s[i]));
        }
    }

    sort(ans.rbegin(), ans.rend());

    rep(i, 0, ans.size())
    {
        ans2.push_back(ans[i].second);

        if (ans[i].first != ans[i + 1].first)
        {
            break;
        }
    }

    sort(ans2.begin(), ans2.end());

    for (auto &x : ans2)
    {
        cout << x << endl;
    }
}