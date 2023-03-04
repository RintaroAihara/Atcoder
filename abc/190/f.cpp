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
    ll n;
    cin >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]++;
    }

    ll ans = 0;

    BIT b(n); // これまでの数字がどんな風になってるのかをメモる為のBIT
    for (int i = 0; i < n; i++)
    {
        ans += i - b.sum(a[i]); // BITの総和 - 自分より左側 ＝ 自分より右側
        b.add(a[i], 1);         // 自分の位置に1を足す(ダジャレではないです)
    }

    cout << ans << endl;

    for (int i = 1; i < n; i++)
    {
        ans += n - a[i - 1] - (a[i - 1] - 1);
        cout << ans << endl;
    }
}
