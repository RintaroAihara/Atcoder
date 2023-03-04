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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    int n;
    cin >> n;

    vector<ll> x(n), y(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int a = x[i] - x[j], b = y[i] - y[j];
                int c = x[j] - x[k], d = y[j] - y[k];

                int p = gcd(a, b), q = gcd(c, d);

                a /= p;
                b /= p;
                c /= q;
                d /= q;

                if (a < 0)
                {
                    a *= -1;
                    b *= -1;
                }

                if (c < 0)
                {
                    c *= -1;
                    d *= -1;
                }

                if (a == c && b == d)
                {
                    cout << "Yes" << endl;
                    return 0;
                }

                if (a == 0 && c == 0)
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
}
