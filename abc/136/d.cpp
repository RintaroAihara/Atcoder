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
    string s;
    int r = 0, l = 0;

    vector<int> ans(100010, 0);

    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'R')
        {
            r++;
        }
        else
        {
            ans[i - 1] += r - r / 2;
            ans[i] += r / 2;
            r = 0;
        }
    }

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == 'L')
        {
            l++;
        }
        else
        {
            ans[i] += l / 2;
            ans[i + 1] += l - l / 2;
            l = 0;
        }
    }

    for (int i = 0; i < s.size(); i++)
    {
        printf("%d%c", ans[i], i == s.size() - 1 ? '\n' : ' ');
    }
}