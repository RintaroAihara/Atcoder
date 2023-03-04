#include <cstdio>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1e18) + 1;

int main(void)
{
    int a, b;

    cin >> a >> b;

    if (a > 9 || b > 9)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << a * b << endl;
    }
}