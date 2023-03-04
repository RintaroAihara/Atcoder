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
    int n;
    string s;
    stack<char> st;

    cin >> s;

    ll ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (st.size() == 0 || st.top() == s[i])
        {
            st.push(s[i]);
        }
        else
        {
            ans += 2;

            st.pop();
        }
    }

    cout << ans << endl;
}
