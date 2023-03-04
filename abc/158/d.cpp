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
#include <stack>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    string s;
    int q;
    bool flag = true;

    cin >> s >> q;

    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            flag = !flag;
        }
        else
        {
            int f;
            char c;
            cin >> f >> c;

            if (f == 1)
            {
                if (flag)
                {
                    s.insert(s.begin(), c);
                }
                else
                {
                    s.insert(s.end(), c);
                }
            }
            else
            {
                if (flag)
                {
                    s.insert(s.end(), c);
                }
                else
                {
                    s.insert(s.begin(), c);
                }
            }
        }
    }

    if (!flag)
    {
        reverse(s.begin(), s.end());
    }

    cout << s << endl;
}