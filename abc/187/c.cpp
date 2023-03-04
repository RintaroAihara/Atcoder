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
    set<string> a, b;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s[0] == '!')
        {
            s.erase(s.begin());
            b.insert(s);
        }
        else
        {
            a.insert(s);
        }
    }

    for (auto &&i : a)
    {
        if (b.find(i) != b.end() && a.find(i) != a.end())
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << "satisfiable" << endl;
}
