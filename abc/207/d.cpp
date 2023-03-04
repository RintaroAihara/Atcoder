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
    ll n;
    cin >> n;

    vector<P> ab(n), cd(n), ncd(n);

    for (int i = 0; i < n; i++)
    {
        cin >> ab[i].first >> ab[i].second;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> cd[i].first >> cd[i].second;
    }

    ll x = ab[0].first, y = ab[0].second;

    for (int i = 0; i < n; i++)
    {
        ab[i].first -= x;
        ab[i].second -= y;
    }

    sort(ab.begin(), ab.end());

    // for (auto &&i : ab)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }

    int cos[4] = {1, 0, -1, 0};
    int sin[4] = {0, 1, 0, -1};

    bool ans = false;

    for (int i = 0; i < n; i++)
    {
        x = cd[i].first, y = cd[i].second;

        for (int j = 0; j < 4; j++)
        {
            bool f = true;
            for (int k = 0; k < n; k++)
            {
                ncd[k].first = (cd[k].first - x) * cos[j] - (cd[k].second - y) * sin[j];
                ncd[k].second = (cd[k].first - x) * sin[j] + (cd[k].second - y) * cos[j];
            }

            sort(ncd.begin(), ncd.end());

            // for (auto &&i : ncd)
            // {
            //     cout << i.first << " " << i.second << endl;
            // }

            for (int k = 0; k < n; k++)
            {
                if (ab[k].first != ncd[k].first || ab[k].second != ncd[k].second)
                {
                    f = false;
                }
            }

            if (f)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}