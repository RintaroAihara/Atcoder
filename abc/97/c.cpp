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
    ll k;
    cin >> s >> k;

    set<string> ans;

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i + j > s.size())
            {
                break;
            }

            ans.insert(s.substr(i, j));
        }
    }

    ll x = 1;

    for (auto &&i : ans)
    {
        if (x == k)
        {
            cout << i << endl;
            return 0;
        }
        x++;
    }
}