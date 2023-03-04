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
    ll n, a, b, c;

    cin >> n >> a >> b >> c;

    vector<string> s(n);
    vector<char> ans(n);

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == "AB")
        {
            if (a == 0 && b == 0)
            {
                cout << "No" << endl;
                return 0;
            }

            if (a > b)
            {
                b++;
                a--;

                ans[i] = 'B';
            }
            else if (b > a)
            {
                a++;
                b--;

                ans[i] = 'A';
            }
            else
            {
                if (i != n - 1)
                {
                    if (s[i + 1] == "AC" || s[i + 1] == "AB")
                    {
                        a++;
                        b--;

                        ans[i] = 'A';
                    }

                    if (s[i + 1] == "BC")
                    {
                        b++;
                        a--;

                        ans[i] = 'B';
                    }
                }
                else
                {
                    a++;
                    b--;

                    ans[i] = 'A';
                }
            }
        }

        if (s[i] == "AC")
        {
            if (a == 0 && c == 0)
            {
                cout << "No" << endl;
                return 0;
            }

            if (a > c)
            {
                c++;
                a--;

                ans[i] = 'C';
            }
            else if (c > a)
            {
                a++;
                c--;

                ans[i] = 'A';
            }
            else
            {
                if (i != n - 1)
                {
                    if (s[i + 1] == "AB" || s[i + 1] == "AC")
                    {
                        a++;
                        c--;

                        ans[i] = 'A';
                    }

                    if (s[i + 1] == "BC")
                    {
                        c++;
                        a--;

                        ans[i] = 'C';
                    }
                }
                else
                {
                    a++;
                    c--;

                    ans[i] = 'A';
                }
            }
        }

        if (s[i] == "BC")
        {
            if (b == 0 && c == 0)
            {
                cout << "No" << endl;
                return 0;
            }

            if (b > c)
            {
                c++;
                b--;

                ans[i] = 'C';
            }
            else if (c > b)
            {
                b++;
                c--;

                ans[i] = 'B';
            }
            else
            {
                if (i != n - 1)
                {
                    if (s[i + 1] == "AC" || s[i + 1] == "BC")
                    {
                        c++;
                        b--;

                        ans[i] = 'C';
                    }

                    if (s[i + 1] == "AB")
                    {
                        b++;
                        c--;

                        ans[i] = 'B';
                    }
                }
                else
                {
                    b++;
                    c--;

                    ans[i] = 'B';
                }
            }
        }
    }

    cout << "Yes" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
}