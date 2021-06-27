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

int BIT[1000010];

void upd(int x,int val)
{
    for ( ; x <= 1000000 ; x += (x & -x))
        BIT[x] += val;
}

int query(int x)
{
    int ret = 0;
    for ( ; x ; x -= (x & -x))
        ret += BIT[x];
    return ret;
}

int kthElement(int k)
{
    int l = 1;
    int r = 1000000;
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        int cnt = query(mid);
        if (cnt >= k)
            r = mid;
        else
            l = mid + 1;
    }
    if (query(l) >= k) return l;
    else return r;
}

void solve()
{
    int n,q;
    cin >> n >> q;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        upd(ta,1);
    }
    int cnt = n;
    for (int i = 1 ; i <= q ; i++)
    {
        int k;
        cin >> k;
        if (k < 0)
        {
            --cnt;
            k *= -1;
            int element = kthElement(k);
            upd(element,-1);
        }
        else
        {
            upd(k,1);
            ++cnt;
        }
    }
    if (cnt == 0)
        cout << 0 << endl;
    else
    {
        for (int i = 1 ; i <= n ; i++)
        {
            if (query(i) - query(i - 1) > 0)
            {
                cout << i << endl;
                return;
            }
        }
    }
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