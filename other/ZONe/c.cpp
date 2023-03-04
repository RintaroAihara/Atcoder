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
    string s;
    cin >> s;

    deque<char> t;

    bool flag = true;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'R')
        {
            flag = !flag;
        }
        else
        {
            if (flag)
            {
                t.push_back(s[i]);
            }
            else
            {
                t.push_front(s[i]);
            }
        }
    }

    deque<char> q;

    if (flag)
    {
        for (int i = 0; i < t.size(); i++)
        {
            if (q.size())
            {
                if (q.back() == t[i])
                {
                    q.pop_back();
                }
                else
                {
                    q.push_back(t[i]);
                }
            }
            else
            {
                q.push_back(t[i]);
            }
        }
    }
    else
    {
        for (int i = t.size() - 1; i >= 0; i--)
        {
            if (q.size())
            {
                if (q.back() == t[i])
                {
                    q.pop_back();
                }
                else
                {
                    q.push_back(t[i]);
                }
            }
            else
            {
                q.push_back(t[i]);
            }
        }
    }

    for (int i = 0; i < q.size(); i++)
    {
        cout << q[i];
    }

    cout << endl;
}