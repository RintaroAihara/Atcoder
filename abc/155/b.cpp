#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <queue>
#include <stack>
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1e9 + 7;

int main(void)
{
    int n;
    int a;
    int i;
    bool flag = true;

    cin >> n;

    rep(i, 0, n)
    {
        cin >> a;
        if (a % 2 == 0)
        {
            if (a % 3 == 0 || a % 5 == 0)
            {
            }
            else
            {
                flag = false;
            }
        }
    }

    if (flag)
    {
        cout << "APPROVED" << endl;
    }
    else
    {
        cout << "DENIED" << endl;
    }
}