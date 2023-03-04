#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1e18) + 1;

int main(void)
{
    string s;
    int i;
    int hug = 0;
    int mid;

    cin >> s;

    if (s.size() % 2 == 0)
    {
        mid = s.size() / 2;

        rep(i, 0, s.size() / 2)
        {
            if (s[mid + i] != s[mid - i - 1])
            {
                hug++;
            }
        }
    }
    else
    {
        mid = s.size() / 2;

        rep(i, 0, s.size() / 2 + 1)
        {
            if (s[mid + i] != s[mid - i])
            {
                hug++;
            }
        }
    }

    cout << hug << endl;
}