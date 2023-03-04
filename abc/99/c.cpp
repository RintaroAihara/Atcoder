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
        a = b; // aをbで更新
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b; // aをbで更新
        return true;
    }
    return false;
}

vector<ll> memo;

ll rec(ll n)
{
    if (memo[n] != INF)
    {
        return memo[n];
    }

    int x = 1;

    for (int i = 0; i < 100; i++)
    {
        if (n - x < 0)
        {
            break;
        }

        chmin(memo[n], rec(n - x) + 1);
        x *= 6;
    }

    x = 1;

    for (int i = 0; i < 100; i++)
    {
        if (n - x < 0)
        {
            break;
        }

        chmin(memo[n], rec(n - x) + 1);
        x *= 9;
    }

    return memo[n];
}

int main(void)
{
    int n;
    cin >> n;

    memo.assign(n + 1, INF);
    memo[0] = 0;

    cout << rec(n) << endl;
}
