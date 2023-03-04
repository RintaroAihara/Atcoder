#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#define rep(i, s, g) for (i = s; i <= g; i++)
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main(void)
{
    int a, b;
    int i;

    cin >> a >> b;

    if (a < b)
    {
        rep(i, 1, b)
        {
            cout << a;
        }
        cout << endl;
    }
    else
    {
        rep(i, 1, a)
        {
            cout << b;
        }
        cout << endl;
    }
}