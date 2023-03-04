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
    ll t;
    cin >> t;

    string atcoder = "atcoder";

    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;

        ll ans = 0;
        bool flag = false;

        for (int j = 0; j < s.size(); j++)
        {
            if (atcoder < s)
            {
                flag = true;
                break;
            }

            char tmp = 'a';

            ll x = j;

            for (int k = j + 1; k < s.size(); k++)
            {
                if (chmax(tmp, s[k]))
                {
                    x = k;
                }
            }

            if (tmp > s[j])
            {
                swap(s[j], s[x]);
                ans++;
            }
            else
            {
                break;
            }
        }

        if (atcoder < s)
        {
            flag = true;
        }

        if (!flag)
        {
            ans = -1;
        }

        cout << ans << endl;
    }
}