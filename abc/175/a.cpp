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
    int ans = 0;
    string s;
    cin >> s;

    if (s == "RRR")
    {
        cout << 3 << endl;
    }
    else if (s == "RSR" || s == "SSR" || s == "SRS" || s == "RSS")
    {
        cout << 1 << endl;
    }
    else if (s == "RRS" || s == "SRR")
    {
        cout << 2 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}
