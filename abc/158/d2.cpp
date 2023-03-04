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

    deque<char> sdq(s.size());

    for (int i = 0; i < s.size(); i++)
    {
        sdq[i] = s[i];
    }

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
                    sdq.push_front(c);
                }
                else
                {
                    sdq.push_back(c);
                }
            }
            else
            {
                if (!flag)
                {
                    sdq.push_front(c);
                }
                else
                {
                    sdq.push_back(c);
                }
            }
        }
    }

    if (flag)
    {
        for (int i = 0; i < sdq.size(); i++)
        {
            printf("%c", sdq[i]);
        }
    }
    else
    {
        for (int i = sdq.size() - 1; i >= 0; i--)
        {
            printf("%c", sdq[i]);
        }
    }

    printf("\n");
}