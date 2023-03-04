#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
#include <stack>
#define rep(i, s, g) for (i = s; i <= g; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b)
{
    ll tmp;
    ll c;
    if (a < b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }

    do
    {
        c = a % b;
        a = b;
        b = c;
    } while (c != 0);

    return a;
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

int two(int a)
{
    int ans = 0;

    while (a % 2 == 0)
    {
        ans++;
        a /= 2;
    }

    return ans;
}

int main(void)
{
    int N, M;
    int a;
    int i, j;
    ll l = 1;
    int ans = 0;
    int flag;

    cin >> N >> M;

    cin >> a;
    a /= 2;
    l = lcm(l, a);
    flag = two(a);

    rep(i, 0, N - 2)
    {
        cin >> a;
        a /= 2;
        if (flag != two(a))
        {
            cout << 0 << endl;
            return 0;
        }

        l = lcm(l, a);
    }

    
    cout << (M / l + 1) / 2 << endl;
}