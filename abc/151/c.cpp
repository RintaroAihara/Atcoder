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
    int N, M;
    int p;
    string S;
    int i, j;
    vector<pair<bool, int>> judge(100010, make_pair(false, 0));
    int ac = 0, wa = 0;

    cin >> N >> M;

    rep(i, 1, M)
    {
        cin >> p >> S;

        if (judge[p].first == false)
        {
            if (S == "AC")
            {
                ac++;
                judge[p].first = true;
            }
            else
            {
                wa++;
                judge[p].second++;
            }
        }
    }

    rep(i, 1, N)
    {
        if (judge[i].first == false)
        {
            wa -= judge[i].second;
        }
    }

    cout << ac << " " << wa << endl;
}