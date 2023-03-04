#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 62) - 1;

int main(void)
{
    int n, m;
    vector<int> s, c;
    int i, j;
    bool flag;
    int b, g;

    cin >> n >> m;

    s.resize(m);
    c.resize(m);

    rep(i, 0, m)
    {
        cin >> s[i] >> c[i];
    }

    if (n == 1)
    {
        b = 0;
        g = 10;
    }
    if (n == 2)
    {
        b = 10;
        g = 100;
    }

    if (n == 3)
    {
        b = 100;
        g = 1000;
    }

    rep(i, b, g)
    {
        flag = true;
        rep(j, 0, m)
        {
            if (n - s[j] == 2)
            {
                if (i / 100 != c[j])
                {
                    flag = false;
                }
            }

            if (n - s[j] == 1)
            {
                if ((i % 100) / 10 != c[j])
                {
                    flag = false;
                }
            }

            if (n - s[j] == 0)
            {
                if (i % 10 != c[j])
                {
                    flag = false;
                }
            }
        }

        if (flag)
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}