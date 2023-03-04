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
    cin >> n;

    vector<string> w(n);
    set<string> s;
    cin >> w[0];
    s.insert(w[0]);

    for (int i = 1; i < n; i++)
    {
        cin >> w[i];

        if (s.find(w[i]) != s.end() || *w[i - 1].rbegin() != *w[i].begin())
        {
            cout << "No" << endl;
            return 0;
        }

        s.insert(w[i]);
    }

    cout << "Yes" << endl;
}
