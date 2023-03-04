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
    int k = 0;

    cin >> n;

    vector<int> p(n), p1(n);

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        p1[i] = p[i];
    }

    sort(p.begin(), p.end());

    for (int i = 0; i < n; i++)
    {
        if (p[i] != p1[i])
        {
            k++;
        }
    }

    if (k <= 2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}