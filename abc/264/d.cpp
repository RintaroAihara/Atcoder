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

struct BIT
{
private:
    vector<int> bit;
    int N;

public:
    BIT(int size)
    {
        N = size;
        bit.resize(N + 1);
    }

    // 一点更新です
    void add(int a, int w)
    {
        for (int x = a; x <= N; x += x & -x)
            bit[x] += w;
    }

    // 1~Nまでの和を求める。
    int sum(int a)
    {
        int ret = 0;
        for (int x = a; x > 0; x -= x & -x)
            ret += bit[x];
        return ret;
    }
};

int main(void)
{
    string s;
    cin >> s;

    map<char, int> m;

    m['a'] = 1;
    m['t'] = 2;
    m['c'] = 3;
    m['o'] = 4;
    m['d'] = 5;
    m['e'] = 6;
    m['r'] = 7;

    ll ans = 0;

    BIT b(7);

    for (int i = 0; i < 7; i++)
    {
        ans += i - b.sum(m[s[i]]);
        b.add(m[s[i]], 1);
    }

    cout << ans << endl;
}