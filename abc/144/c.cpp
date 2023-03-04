#include <cstdio>
#include <cstring>
#include <cmath>
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
    ll n;
    ll i;

    cin >> n;

    for (i = sqrt(n) + 1; i >= 1; i--)
    {
        if (n % i == 0)
        {
            n /= i;
            break;
        }
    }

    cout << i + n - 2 << endl;
}