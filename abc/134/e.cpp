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
    int n;
    cin >> n;

    multiset<int> s;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        if (s.empty() || *s.begin() >= a)
        {
            s.insert(a);
        }
        else
        {
            auto x = s.lower_bound(a);
            x--;
            s.erase(x);
            s.insert(a);
        }
    }

    cout << s.size() << endl;
}