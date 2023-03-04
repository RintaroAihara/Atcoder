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

    vector<int> d(n);

    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    sort(d.begin(), d.end());

    cout << d[n / 2] - d[n / 2 - 1] << endl;
}