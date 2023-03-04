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

    ll ans = 0;
    ll res = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]=='A'||s[i]=='G'||s[i]=='T'||s[i]=='C')
        {
            res++;
        }
        else
        {
            res = 0;
        }

        ans = max(ans, res);
    }

    cout << ans << endl;
}