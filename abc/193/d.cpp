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
    ll k;
    cin >> k;
    string s, t;
    cin >> s >> t;

    map<ll, ll> num;

    for (int i = 1; i < 10; i++)
    {
        num[i] = k;
    }

    for (int i = 0; i < 4; i++)
    {
        num[s[i] - '0']--;
        num[t[i] - '0']--;
    }

    ll a = 0, b = (k * 9 - 8) * (k * 9 - 9);

    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            map<ll, ll> ta, ao;

            if (num[i] <= 0 || num[j] <= 0)
            {
                continue;
            }

            if (i == j)
            {
                if (num[i] <= 1)
                {
                    continue;
                }
            }

            for (int l = 0; l < 4; l++)
            {
                ta[s[l] - '0']++;
                ao[t[l] - '0']++;
            }

            ta[i]++;
            ao[j]++;

            ll pt = 0, pa = 0;

            for (int l = 1; l < 10; l++)
            {
                pt += l * power(10ll, ta[l]);
                pa += l * power(10ll, ao[l]);
            }

            if (pt > pa)
            {
                if (i == j)
                {
                    a += num[i] * (num[j] - 1);
                }
                else
                {
                    a += num[i] * num[j];
                }

                // cout << i << j << endl;
            }
        }
    }

    // ll g = gcd(a, b);

    // a /= g;
    // b /= g;

    printf("%.10f\n", (double)a / (double)b);
}