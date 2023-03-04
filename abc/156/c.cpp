#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1e18) + 1;

int main(void)
{
    int n;
    vector<int> x;
    int i, j;
    ll sum;
    ll ans = INF;

    cin >> n;

    x.resize(n); //xのサイズをnに変更

    rep(i, 0, n)
    {
        cin >> x[i]; //代入
    }

    rep(i, 1, 101) 
    {
        sum = 0;
        rep(j, 0, n)
        {
            sum += (x[j] - i) * (x[j] - i); //集会が座標iで開かれる時の住人との距離
        }

        ans = min(sum, ans); //今までのより小さかったらそれに更新
    }

    cout << ans << endl;
}