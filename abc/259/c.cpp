#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

int main(void)
{
    string s, t;
    cin >> s >> t;
    vector<pair<char, int>> ss, tt;

    char c = s[0];
    int cnt = 1;

    for (int i = 1; i < s.size(); i++)
    {
        if (c == s[i])
        {
            cnt++;
        }
        else
        {
            ss.push_back({c, cnt});
            cnt = 1;
            c = s[i];
        }
    }
    ss.push_back({c, cnt});

    c = t[0];
    cnt = 1;
    for (int i = 1; i < t.size(); i++)
    {
        if (c == t[i])
        {
            cnt++;
        }
        else
        {
            tt.push_back({c, cnt});
            cnt = 1;
            c = t[i];
        }
    }
    tt.push_back({c, cnt});

    if (ss.size() != tt.size())
    {
        cout << "No" << endl;
        return 0;
    }

    for (int i = 0; i < ss.size(); i++)
    {
        if (ss[i].first == tt[i].first)
        {
            if (ss[i].second == 1)
            {
                if (ss[i].second == tt[i].second)
                {
                }
                else
                {
                    cout << "No" << endl;
                    return 0;
                }
            }
            else
            {
                if (ss[i].second > tt[i].second)
                {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
        else
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}