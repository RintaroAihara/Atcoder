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

    for (int i = 0; i < t; i++)
    {
        ll n;
        cin >> n;

        if (n % 2 == 0)
        {
            if ((n / 2) % 2 == 1)
            {
                cout << "Same" << endl;
            }
            else
            {
                cout << "Even" << endl;
            }
        }
        else
        {
            cout << "Odd" << endl;
        }
    }
}