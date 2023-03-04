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
    string s;
    cin >> s;
    map<ll, ll> m;

    for (int i = 0; i < s.size(); i++)
    {
        m[s[i] - '0']++;
    }

    if (s.size() == 1)
    {
        if (s == "8")
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    else if (s.size() == 2)
    {
        if (stoi(s) % 8 == 0)
        {
            cout << "Yes" << endl;
            return 0;
        }

        reverse(s.begin(), s.end());

        if (stoi(s) % 8 == 0)
        {
            cout << "Yes" << endl;
            return 0;
        }
        }
    else
    {
        for (int i = 112; i < 1000; i += 8)
        {
            int x = i;

            map<ll, ll> n;
            bool flag = true;

            for (int i = 0; i < 3; i++)
            {
                if (x % 10 == 0)
                {
                    flag = false;
                }

                n[x % 10]++;
                x /= 10;
            }

            for (int j = 0; j < 10; j++)
            {
                if (n[j] > m[j])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}
