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
    vector<ll> v(3);

   for (int i = 0; i < 3; i++)
   {
       cin >> v[i];
   }

   sort(v.begin(), v.end());

   ll ans = 0;

   ans = v[2] * 10 + v[1] + v[0];

   cout << ans << endl;
}
