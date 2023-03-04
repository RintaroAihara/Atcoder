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
    int N;
    int p[10], q[10];
    int i, j;
    int a = 1, b = 1;

    cin >> N;

    vector<int> per(N, 0);

    rep(i, 0, N)
    {
        per[i] = i + 1;
    }

    rep(i, 0, N)
    {
        cin >> p[i];
    }

    do
    {
        rep(i, 0, N)
        {
            if (per[i] == p[i])
            {
                continue;
            }
            else
            {
                break;
            }
        }

        if (i == N)
        {
            break;
        }

        a++;

    } while (next_permutation(per.begin(), per.end()));

    rep(i, 0, N)
    {
        per[i] = i + 1;
    }

    rep(i, 0, N)
    {
        cin >> q[i];
    }

    do
    {
        rep(i, 0, N)
        {
            if (per[i] == q[i])
            {
                continue;
            }
            else
            {
                break;
            }
        }

        if (i == N)
        {
            break;
        }

        b++;

    } while (next_permutation(per.begin(), per.end()));

    cout << abs(a - b) << endl;
}