#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
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
    int a, b, c;
    int k;
    cin >> a >> b >> c >> k;

    int cnt = 0;

    while (true)
    {
        if (a < b)
        {
            break;
        }
        b <<= 1;
        cnt++;
    }

    while (true)
    {

        if (b < c)
        {
            break;
        }
        c <<= 1;
        cnt++;
    }

    if (k < cnt)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
}
