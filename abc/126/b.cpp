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

    cin >> s;

    int a, b;

    a = 10 * (s[0] - '0') + s[1] - '0';

    b = 10 * (s[2] - '0') + s[3] - '0';

    if (a <= 12 && b <= 12 && a > 0 && b > 0)
    {
        cout << "AMBIGUOUS" << endl;
    }
    else if (a <= 12 && a > 0)
    {
        cout << "MMYY" << endl;
    }
    else if (b <= 12 && b > 0)
    {
        cout << "YYMM" << endl;
    }
    else
    {
        cout << "NA" << endl;
    }
}