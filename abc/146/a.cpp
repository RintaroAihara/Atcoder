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
    string s;

    cin >> s;

    if (s == "SUN")
    {
        cout << 7 << endl;
    }
    else if (s == "MON")
    {
        cout << 6 << endl;
    }
    else if (s == "TUE")
    {
        cout << 5 << endl;
    }
    else if (s == "WED")
    {
        cout << 4 << endl;
    }
    else if (s == "THU")
    {
        cout << 3 << endl;
    }
    else if (s == "FRI")
    {
        cout << 2 << endl;
    }
    else if (s == "SAT")
    {
        cout << 1 << endl;
    }
}