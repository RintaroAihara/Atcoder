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
#include <cassert>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    string s;
    cin >> s;

    vector<vector<ll>> alp(26, vector<ll>(s.size() + 1, 0));
    vector<ll> able;

    for (int i = 0; i < s.size(); i++)
    {
        alp[s[i] - 'a'][i + 1] += 1;

        if (i < s.size() - 2)
        {
            if (s[i] == s[i + 1] && s[i] != s[i + 2])
            {
                able.push_back(i + 1);
            }
        }
    }

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < s.size(); j++)
        {
            alp[i][j + 1] += alp[i][j];
        }
    }

    ll ans = 0;

    ll tmp = s.size();
    char mae = 'A';

    for (int i = able.size() - 1; i >= 0; i--)
    {
        char now = s[able[i]];

        if (now == mae)
        {
            ans += tmp - able[i] - 1 - (alp[now - 'a'][tmp] - alp[now - 'a'][able[i] + 1]);
        }
        else
        {
            ans += s.size() - able[i] - 1 - (alp[now - 'a'][tmp] - alp[now - 'a'][able[i] + 1]);
        }

        mae = now;
        tmp = able[i];
    }

    cout << ans << endl;
}