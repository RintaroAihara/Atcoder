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

class node
{
public:
    ll value, parent;
    ll child;
    node(ll v, ll p)
    {
        value = v;
        parent = p;
    };
};

int main(void)
{
    ll q;
    cin >> q;

    map<ll, ll> note;
    vector<node> tree;
    tree.push_back(node(-1, 0));
    ll v = 0;
    for (int i = 0; i < q; i++)
    {
        string s;
        ll x;
        cin >> s;

        if (s == "ADD")
        {
            ll x;
            cin >> x;
            tree.back().child = tree.size();
            tree.push_back(node(x, v));
            v = tree.size()-1;
        }
        else if (s == "DELETE")
        {
            v = tree[v].parent;
        }
        else if (s == "SAVE")
        {
            ll y;
            cin >> y;
            note[y] = v;
        }
        else if (s == "LOAD")
        {
            ll z;
            cin >> z;
            v = note[z];
        }

        cout << tree[v].value << endl;
    }
}