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
#include <fstream>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

ll d;
vector<ll> c(26 + 1);
vector<vector<ll>> s(365 + 1, vector<ll>(26 + 1));

ll scoring(vector<ll> t)
{
    ll ans = 0;
    vector<ll> last(26 + 1, 0);

    for (int i = 1; i <= d; i++)
    {
        ans += s[i][t[i]];
        ans -= c[t[i]] * (i - last[t[i]]) * (i - last[t[i]] - 1) / 2;
        last[t[i]] = i;
    }

    for (int i = 1; i <= 26; i++)
    {

        ans -= c[i] * (d - last[i] + 1) * (d - last[i]) / 2;
    }

    return ans;
}

int main(void)
{
    cin >> d;

    for (int i = 1; i <= 26; i++)
    {
        cin >> c[i];
    }

    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= 26; j++)
        {
            cin >> s[i][j];
        }
    }

    vector<ll> t(d + 1);

    ofstream outputfile("test.txt");

    for (int j = 0; j < 26; j++)
    {
        for (int k = 0; k < 26; k++)
        {
            for (int l = 0; l < 26; l++)
            {
                for (int m = 0; m < 26; m++)
                {
                    t[1] = 1;
                    t[2] = j + 1;
                    t[3] = k + 1;
                    t[4] = l + 1;
                    t[5] = m + 1;

                    outputfile << scoring(t) << endl;
                }
            }
        }
    }

    outputfile.close();
}
