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

template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

int main(void)
{
    ll n;
    cin >> n;

    vector<string> ans;

    for (int i = 0; i < (1 << n); i++)
    {
        string s;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                s.push_back('(');
            }
            else
            {
                s.push_back(')');
            }
        }

        queue<char> q;
        bool f = true;

        for (int j = 0; j < n; j++)
        {
            if (s[j] == '(')
            {
                q.push('(');
            }
            else
            {
                if (q.size())
                {
                    q.pop();
                }
                else
                {
                    f = false;
                    break;
                }
            }
        }

        if (f && q.empty())
        {
            ans.push_back(s);
        }
    }

    sort(ans.begin(), ans.end());

    for (auto &&i : ans)
    {
        cout << i << endl;
    }
}