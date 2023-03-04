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
    char a, b;

    cin >> s;

    sort(s.begin(), s.end());

    if (s[0] == s[1] && s[2] == s[3] && s[0] != s[3])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}