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
    ll n;
    string s;
    cin >> n >> s;

    deque<char> q;
    string fox = "";

    for (int i = 0; i < n; i++)
    {
        q.push_front(s[i]);

        if (q.size() >= 3)
        {
            string fox = "";
            for (int j = 3 - 1; j >= 0; j--)
            {
                fox += q[j];
            }

            if (fox == "fox")
            {
                for (int j = 3 - 1; j >= 0; j--)
                {
                    q.pop_front();
                }
            }
        }
    }

    cout << q.size() << endl;
}
