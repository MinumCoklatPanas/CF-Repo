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
#define MULTI_TC 1

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

struct hero
{
    int p,s;
    hero(){}
    hero(int _p,int _s)
    {
        p = _p;
        s = _s;
    }
    bool operator< (hero &other) const
    {
        return make_pair(s,p) < make_pair(other.s,other.p);
    }
    bool operator> (hero &other) const
    {
        return make_pair(s,p) > make_pair(other.s,other.p);
    }
};


void solve()
{
    int n;
    cin >> n;
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    int m;
    cin >> m;
    vector<hero> a(m);
    for (auto &it : a) cin >> it.p >> it.s;
    sort(a.begin(),a.end(),[&](hero &x,hero &y)
    {
        return (make_pair(x.p,x.s) < make_pair(y.p,y.s));
    });
    vector<hero> suf(m);
    suf[m - 1] = a[m - 1];
    for (int i = m - 2 ; i >= 0 ; i--) 
    {
        if (suf[i + 1] > a[i])
            suf[i] = suf[i + 1];
        else
            suf[i] = a[i];
    }
    const auto upperBound = [&](int x) -> int
    {
        if (a.back().p < x) return -1;
        int l = 0;
        int r = m - 1;
        while (r - l > 1)
        {
            int mid = (l + r) >> 1;
            if (a[mid].p >= x)
                r = mid;
            else
                l = mid + 1;
        }
        // cerr << l << " " << r << " " << a[l].p << " " << x << endl;
        if (a[l].p >= x) return l;
        else return r;
    };
    int ans = 1;
    int ix = upperBound(tab[0]);    
    // cerr << ix << endl;
    // return;
    if (ix == -1)
    {
        cout << -1 << endl;
        return;
    }
    hero cur = suf[ix];
    int curStep = 1;
    // return;
    for (int i = 1 ; i < n ; i++)
    {
        ++curStep;
        if (curStep > cur.s)
        {
            ix = upperBound(tab[i]);
            if (ix == -1)
            {
                cout << -1 << endl;
                return;
            }
            cur = suf[ix];
            curStep = 1;
            ++ans;
        }
        else
        if (tab[i] > cur.p)
        {
            ix = upperBound(tab[i]);
            if (ix == -1)
            {
                cout << ix << endl;
                return;
            }
            cur = suf[ix];
            if (cur.s < curStep)
            {
                ++ans;
                curStep = 1;
            }
        }
    }
    cout << ans << endl;
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