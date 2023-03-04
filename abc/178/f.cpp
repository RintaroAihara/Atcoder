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
    ll n;
    cin >> n;

    vector<ll> a(n), ans;
    map<ll, ll> ma, mb;
    deque<ll> q_max, q;
    priority_queue<P> pq;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ma[a[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        ll b;
        cin >> b;
        mb[b]++;
        q.push_front(b);
    }

    ll s = 0;
    ll b_max = 0;

    for (int i = 1; i <= n; i++)
    {
        if (ma[i] + mb[i] > n)
        {
            cout << "No" << endl;
            return 0;
        }

        if (s < ma[i] + mb[i])
        {
            s = ma[i] + mb[i];
            b_max = i;
        }
    }

    for (auto &&i : mb)
    {
        if (i.first == b_max)
        {
            for (int j = 0; j < i.second; j++)
            {
                q_max.push_front(i.first);
            }
        }
        else
        {
            for (int j = 0; j < i.second; j++)
            {
                q.push_front(i.first);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] != q_max.front() && q_max.size())
        {
            ans.push_back(q_max.front());
            q_max.pop_front();
        }
        else if (a[i] != q.front() && q.size())
        {
            ans.push_back(q.front());
            q.pop_front();
        }
        else if (a[i] != q.back() && q.size())
        {
            ans.push_back(q.back());
            q.pop_back();
        }
    }

    bool flag = true;

    for (int i = 0; i < n; i++)
    {
        if (ans[i] == a[i])
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        cout << "Yes" << endl;

        for (int i = 0; i < n; i++)
        {
            printf("%lld%s", ans[i], i == n - 1 ? "\n" : " ");
        }

        return 0;
    }

    ans.clear();

    for (int i = 0; i < n; i++)
    {
        if (pq.top().second != a[i])
        {
            ans.push_back(pq.top().second);
            mb[pq.top().second]--;

            if (mb[pq.top().second] == 0)
            {
                pq.pop();
            }
        }
        else
        {
            P p = pq.top();
            pq.pop();

            ans.push_back(pq.top().second);
            mb[pq.top().second]--;

            if (mb[pq.top().second] == 0)
            {
                pq.pop();
            }

            pq.push(p);
        }
    }

    cout << "Yes" << endl;

    for (int i = 0; i < n; i++)
    {
        printf("%lld%s", ans[i], i == n - 1 ? "\n" : " ");
    }
}
