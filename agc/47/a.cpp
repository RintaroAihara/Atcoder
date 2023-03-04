#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    ll n;
    cin >> n;

    vector<vector<ll>> x(20, vector<ll>(20, 0));

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        bool flag = false;
        string g;

        for (int j = 0; j < s.size(); j++)
        {
            if (flag)
            {
                g.push_back(s[j]);
            }

            if (s[j] == '.')
            {
                flag = true;
            }
        }

        while (g.size() < 9)
        {
            g.push_back('0');
        }

        ll z = stol(s) * 1000000000ll + stol(g);


        int t = 0;
        int f = 0;

        while (z % 2 == 0)
        {
            z /= 2;
            t++;
        }

        while (z % 5 == 0)
        {
            z /= 5;
            f++;
        }

        x[min(18, t)][min(18, f)] += 1;
    }

    ll ans = 0;

    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            for (int k = 0; k < 19; k++)
            {
                for (int l = 0; l < 19; l++)
                {
                    if (i + k < 18 || j + l < 18)
                    {
                        continue;
                    }

                    if (i == k && j == l)
                    {
                        ans += x[i][j] * (x[i][j] - 1);
                    }
                    else
                    {
                        ans += x[i][j] * x[k][l];
                    }
                }
            }
        }
    }

    cout << ans / 2 << endl;
}
