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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < k; i++)
    {
        vector<int> a2(n, 0);
        map<int, int> m;

        for (int j = 0; j < n; j++)
        {
            a2[max(0, j - a[j])] += 1;
            if (j + a[j] + 1 < n)
            {
                a2[j + a[j] + 1] -= 1;
            }
        }

        m[a2[0]]++;

        for (int j = 0; j < n - 1; j++)
        {
            a2[j + 1] += a2[j];
            m[a2[j + 1]]++;
        }

        a = a2;

        if (m[n] == n)
        {
            break;
        }
    }

    for (auto &&i : a)
    {
        cout << i << endl;
    }
}
