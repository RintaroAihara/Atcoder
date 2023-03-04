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
    queue<int> q;
    for (int i = 0; i < 600; i++)
    {
        q.push(600 - i);
    }

    ll ans = 0;

    while (q.size())
    {
        ans += 1;
        int s = 0;

        while (true)
        {
            if (s + q.front() > 5000)
            {
                break;
            }

            s += q.front();
            q.pop();
            if (q.empty())
            {
                break;
            }
        }
    }

    cout << ans << endl;
}
