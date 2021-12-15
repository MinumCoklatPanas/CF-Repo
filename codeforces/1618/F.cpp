#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define MULTI_TC 0

int getTC()
{
    if (MULTI_TC)
    {
        int t;
        cin >> t;
        return t;
    }
    else return 1;
}


string toBit(int k)
{
    string ret = "";
    while (k)
    {
        ret += '0' + (k % 2);
        k /= 2;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

int transform0(int x)
{
    int hehe = x * 2;
    string b1 = toBit(hehe);
    hehe = 0;
    for (int i = 0 ; i < b1.size() ; i++) if (b1[i] == '1')
        hehe += (1ll << i);
    return hehe;
}

int transform1(int x)
{
    int hehe = x * 2 + 1;
    string b1 = toBit(hehe);
    hehe = 0;
    for (int i = 0 ; i < b1.size() ; i++) if (b1[i] == '1')
        hehe += (1ll << i);
    return hehe;
}

int a,b;
map<int,bool> vis;

bool rec(int x)
{
    // cerr << x << endl;
    // if (x > b) 
    // {
    //     int tmp = transform0(x);
    //     return (tmp == b) || (transform1(x) == b);
    // }
    if (!x) return 0;
    if (x == b) return 1;
    if (vis[x]) return 0;
    vis[x] = 1;
    // if (nxt > b) return 0;
    bool ret = 0;
    int transformGenap = transform1(x);
    int transformGanjil = transform0(x);
    // if (x & 1ll)
    //     transformGanjil = x;
    // else
    //     transformGanjil = transform0(x);
    // cerr << x<< ' ' << transformGanjil << " " << transformGenap << endl;
    // int nextTransformGanjil = transform0(transformGanjil);
    // ret |= (b == transformGanjil || b == nextTransformGanjil);
    if (!ret)
    {
        ret |= rec(transformGenap);
        if (ret) return true;
        ret |= rec(transformGanjil);
    }
    return ret;
}

void solve()
{
    cin >> a >> b;
    if ((a % 2 == 1) && (b % 2 == 0))
    {
        cout << "NO\n";
        return;
    }
    // cerr << transform0(a) << endl;
    // return;
    // int transformGanjil;
    // if (a & 1)
    //     transformGanjil = a;
    // else
    //     transformGanjil = transform0(a);
    // int nextTransformGanjil = transform0(transformGanjil);
    // if (b == transformGanjil || b == nextTransformGanjil)
    // {
    //     cout << "YES\n";
    //     return;
    // }
    // if (a % 2 == 1)
    //     a = a * 2 + 1;
    if (rec(a))
        cout << "YES\n";
    else
        cout << "NO\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = getTC();
    while (t--)
    {
        solve();
    }
    return 0;
}