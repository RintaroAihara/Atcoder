#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i, s, g) for (i = s; i <= g; i++)
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main(void)
{
    string s, t, ans;
    static int dp[3010][3010];
    int i, j;

    cin >> s >> t;

    s.insert(s.begin(), 0);
    t.insert(t.begin(), 0);

    rep(i, 0, s.size() - 2)
    {
        rep(j, 0, t.size() - 2)
        {
            if (s[i + 1] == t[j + 1])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
            {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    i = s.size() - 1;
    j = t.size() - 1;

    while (1)
    {
        if (dp[i - 1][j - 1] == dp[i][j] - 1 && dp[i - 1][j] == dp[i][j] - 1 && dp[i][j - 1] == dp[i][j] - 1)
        {
            ans.insert(ans.begin(), s[i]);
            i--;
            j--;
        }
        else if (dp[i - 1][j - 1] != dp[i][j] && dp[i][j - 1] == dp[i][j])
        {
            j--;
        }
        else
        {
            i--;
        }

        if (i == 0 || j == 0)
        {
            break;
        }
    }

    cout << ans << endl;
}
