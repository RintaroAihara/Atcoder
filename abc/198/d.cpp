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

ll n;

void dfs(vector<bool> used, map<char, int> m, ll d)
{
    if (d == n)
    {
        return;
    }

    for (int i = 0; i < 10; i++)
    {
    }
}

int main(void)
{
    vector<string> s(3);
    cin >> s[0] >> s[1] >> s[2];

    set<char> se;
    map<char, int> m;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < s[i].size(); j++)
        {
            se.insert(s[i][j]);
            m[s[i][j]] = -1;
        }
    }

    n = se.size();

    if (n > 10)
    {
        cout << "UNSOLVABLE" << endl;
        return 0;
    }

    vector<ll> v(10);

    for (int i = 0; i < 10; i++)
    {
        v[i] = i;
    }

    do
    {
        ll k = 0;

        for (auto &&i : m)
        {
            i.second = v[k];
            k++;
        }

        // for (auto &&i : m)
        // {
        //     cout << i.first << " " << i.second << endl;
        // }

        vector<ll> x(3, 0);

        bool flag = true;

        for (int i = 0; i < 3; i++)
        {
            ll ten = 1ll;

            for (int j = s[i].size() - 1; j >= 0; j--)
            {
                if (j == 0)
                {
                    if (m[s[i][j]] == 0)
                    {
                        flag = false;
                        break;
                    }
                }

                x[i] += ten * m[s[i][j]];
                ten *= 10ll;
            }
        }

        if (x[0] + x[1] != x[2])
        {
            flag = false;
        }

        if (flag)
        {
            for (int i = 0; i < 3; i++)
            {
                cout << x[i] << endl;
            }

            return 0;
        }

    } while (next_permutation(v.begin(), v.end()));

    cout << "UNSOLVABLE" << endl;
}