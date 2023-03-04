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
    int t;

    cin >> t;

    vector<ll> n(t), m(t);

    for (int i = 0; i < t; i++)
    {
        cin >> n[i] >> m[i];
    }

    for (int i = 0; i < t; i++)
    {
        switch (n[i])
        {
        case 1:
            cout << 0 << endl;
            break;

        case 2:
            cout << m[i] << endl;
            break;

        default:
            cout << m[i] * 2 << endl;
            break;
        }
    }
}