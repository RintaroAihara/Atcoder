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
    string s;
    int i;

    cin >> s;

    rep(i, 0, s.size())
    {
        if (i % 2 == 1 && s[i] == 'R')
        {
            cout << "No" << endl;
            return 0;
        }
        else if (i % 2 == 0 && s[i] == 'L')
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}