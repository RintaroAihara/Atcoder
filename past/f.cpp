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
    int n;
    cin >> n;

    vector<vector<bool>> alpha(n, vector<bool>(30, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;

            alpha[i][c - 'a'] = true;
        }
    }

    deque<char> ans;

    int left, right;

    if (n % 2 == 1)
    {
        left = right = n / 2;
    }
    else
    {
        left = n / 2 - 1;
        right = n / 2;
    }

    for (; left >= 0; left--, right++)
    {
        bool flag = false;
        for (int i = 0; i <= 26; i++)
        {
            if (alpha[left][i] && alpha[right][i])
            {
                flag = true;
                if (left == right)
                {
                    ans.push_back((char)(i + 'a'));
                }
                else
                {
                    ans.push_back((char)(i + 'a'));
                    ans.push_front((char)(i + 'a'));
                }
                break;
            }
        }

        if (!flag)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    for (auto x : ans)
    {
        cout << x;
    }

    cout << endl;
}