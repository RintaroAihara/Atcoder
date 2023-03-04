#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
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
    int n;
    string s;
    int i;

    cin >> n >> s;

    rep(i, 0, s.size())
    {
        cout << (char)((s[i] - 'A' + n) % 26 + 'A');
    }

    cout << endl;
}