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

vector<vector<ll>> matrix(vector<vector<ll>> A, vector<vector<ll>> B)
{
    vector<vector<ll>> C(A[0].size(), vector<ll>(B.size(), 0));

    for (int i = 0; i < A[0].size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            for (int k = 0; k < A[0].size(); k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

int main(void)
{
    ll n, m, q;
    cin >> n;
    vector<ll> x(n), y(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    cin >> m;

    vector<vector<vector<ll>>> A(m + 1, vector<vector<ll>>(3, vector<ll>(3, 0)));

    A[0][0][0] = 1;
    A[0][1][1] = 1;
    A[0][2][2] = 1;

    for (int i = 1; i <= m; i++)
    {
        ll op, p;
        vector<vector<ll>> B;
        cin >> op;

        if (op == 1)
        {
            B = {{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}};
            A[i] = matrix(B, A[i - 1]);
        }
        else if (op == 2)
        {
            B = {{0, -1, 0}, {1, 0, 0}, {0, 0, 1}};
            A[i] = matrix(B, A[i - 1]);
        }
        else if (op == 3)
        {
            cin >> p;
            B = {{-1, 0, 2 * p}, {0, 1, 0}, {0, 0, 1}};
            A[i] = matrix(B, A[i - 1]);
        }
        else if (op == 4)
        {
            cin >> p;
            B = {{1, 0, 0}, {0, -1, 2 * p}, {0, 0, 1}};
            A[i] = matrix(B, A[i - 1]);
        }
    }

    cin >> q;

    for (int i = 0; i < q; i++)
    {
        ll a, b;
        cin >> a >> b;
        b--;
        vector<vector<ll>> B{{x[b]}, {y[b]}, {1}};

        vector<vector<ll>> ans = matrix(A[a], B);

        printf("%lld %lld\n", ans[0][0], ans[1][0]);
    }
}
