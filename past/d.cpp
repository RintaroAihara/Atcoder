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
    string s[5];
    int n;
    cin >> n;

    string ans;

    for (int i = 0; i < 5; i++)
    {
        cin >> s[i];
    }

    string c[n][5];

    for (int i = 0; i < n; i++)
    {
        vector<ll> number(5, 0);

        for (int k = 0; k < 5; k++)
        {
            c[i][k] = s[k].substr(1 + i * 4, 3);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (c[i][0] == "###")
        {
            if (c[i][1] == "..#")
            {
                if (c[i][2] == "..#")
                {
                    ans.push_back('7');
                }
                else if (c[i][3] == "..#")
                {
                    ans.push_back('3');
                }
                else if (c[i][3] == "#..")
                {
                    ans.push_back('2');
                }
            }
            else if (c[i][1] == "#..")
            {
                if (c[i][3] == "..#")
                {
                    ans.push_back('5');
                }
                else if (c[i][3] == "#.#")
                {
                    ans.push_back('6');
                }
            }
            else if (c[i][1] == "#.#")
            {
                if (c[i][3] == "..#")
                {
                    ans.push_back('9');
                }
                else if (c[i][2] == "###" && c[i][3] == "#.#")
                {
                    ans.push_back('8');
                }
                else if (c[i][2] == "#.#" && c[i][3] == "#.#")
                {
                    ans.push_back('0');
                }
            }
        }
        else if (c[i][0] == ".#.")
        {
            ans.push_back('1');
        }
        else
        {
            ans.push_back('4');
        }
    }

    cout << ans << endl;
}
