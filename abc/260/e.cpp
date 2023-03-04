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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    vector<vector<int>> ind(m + 1);
    for (int i = 0; i < n; i++)
    {
        ind[a[i]].push_back(i);
        ind[b[i]].push_back(i);
    }
    vector<int> cnt(n), ans(m + 3);
    ll cnt_ab = 0;

    for (int i = 1, j = 1; i <= m;)
    {
        while (j <= m && cnt_ab < n)
        {
            for (auto &&x : ind[j])
            {
                if (cnt[x] == 0)
                {
                    cnt_ab++;
                }
                cnt[x]++;
            }
            j++;
        }

        if (cnt_ab < n)
        {
            break;
        }

        ans[j - i]++;
        ans[m + 1 - i + 1]--;

        for (auto &&x : ind[i])
        {
            cnt[x]--;
            if (cnt[x] == 0)
            {
                cnt_ab--;
            }
        }
        i++;
    }

    for (int i = 1; i <= m; i++)
    {
        ans[i] += ans[i - 1];
        cout << ans[i] << " \n"[i == m];
    }
}