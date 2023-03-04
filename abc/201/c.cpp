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
    ll ans = 0;

    for (int i = 0; i < (1ll << 10); i++)
    {
        bool flag = true;
        ll bit_cnt = 0;

        for (int j = 0; j < 10; j++)
        {
            if (s[j] == 'o')
            {
                if (i & (1 << j))
                {
                    bit_cnt++;
                }
                else
                {
                    flag = false;
                }
            }
            else if (s[j] == 'x')
            {
                if (i & (1 << j))
                {
                    flag = false;
                }
            }
            else
            {
                if (i & (1 << j))
                {
                    bit_cnt++;
                }
            }
        }

        if (bit_cnt > 4)
        {
            flag = false;
        }

        bitset<10> b = i;

        if (flag)
        {
            if (bit_cnt == 4)
            {
                ans += 24ll;
            }
            else if (bit_cnt == 3)
            {
                ans += 36ll;
            }
            else if (bit_cnt == 2)
            {
                ans += 14ll;
            }
            else if (bit_cnt == 1)
            {
                ans += 1ll;
            }
        }
    }

    cout << ans << endl;
}