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
    ll k;
    cin >> s >> k;

    for (int i = 0; i < min((ll)s.size(), k); i++)
    {
        if (s[i] != '1')
        {
            cout << s[i] << endl;
            return 0;
        }
    }

    cout << '1' << endl;
}
