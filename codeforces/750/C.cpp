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

int r[200010];
int d[200010];

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        int a,b;
        cin >> a >> b;
        if (b == 1)
            cout << "Infinity\n";
        else
            cout << 1899 + a << endl;
        return;
    }
    for (int i = 1 ; i <= n ; i++)
        cin >> r[i] >> d[i];
    if (d[1] == 1)
    {
        int curDelta = 0;
        int curIx = 1;
        while (d[curIx] == 1 && curIx <= n)
        {
            curDelta += r[curIx];
            ++curIx;
        }
        if (curIx > n) //kalau div 1 semua berarti infinity
        {
            cout << "Infinity\n";
            return;
        }
        if (curDelta >= 0) //deltanya harus negatif buat turun div2
        {
            cout << "Impossible\n";
            return;
        }
        int lo = 1900 + curDelta;
        int hi = 1899;
        int curDiv = 2;
        for (int i = curIx ; i < n ; i++)
        {
            curDelta = r[i];
            int nextDiv =  d[i + 1];
            if (curDiv == 2 && nextDiv == 2)
            {
                lo += curDelta;
                hi += curDelta;
                if (lo > 1899)
                {
                    // cerr << lo << " " << curDelta << endl;
                    cout << "Impossible\n";
                    return;
                }
                lo = min(lo,1899ll);
                hi = min(hi,1899ll);
            }
            else
            if (curDiv == 2 && nextDiv == 1) //kalau naik divisi deltanya harus positif
            {
                if (curDelta <= 0)
                {
                    cout << "Impossible\n";
                    return;
                }
                lo += curDelta;
                hi += curDelta;
                if (hi < 1900) //kalau kemungkinan max + delta masih < 1900 pasti impossible
                {
                    cout << "Impossible\n";
                    return;
                }
                lo = max(lo,1900ll);
            }
            else
            if (curDiv == 1 && nextDiv == 2) //deltanya harus negatif buat turun div2
            {
                if (curDelta >= 0)
                {
                    cout << "Impossible\n";
                    return;
                }
                lo += curDelta;
                hi += curDelta;
                if (lo > 1899) //kalau kemungkinan min + delta masih >= 1900 pasti impossible
                {
                    cout << "Impossible\n";
                    return;
                }
                hi = min(hi,1899ll);
            }
            else
            {
                lo += curDelta;
                hi += curDelta;
                if (hi < 1900)
                {
                    cout << "Impossible\n";
                    return;
                }
                lo = max(lo,1900ll);
            }
            curDiv = nextDiv;
            // cout << lo << " " << hi << endl;
        }
        cout << hi + r[n] << endl;
    }
    else
    {
        int curDelta = 0;
        int lo = -INFF;
        int hi = 1899;
        int curDiv = 2;
        for (int i = 1 ; i < n ; i++)
        {
            curDelta = r[i];
            int nextDiv =  d[i + 1];
            if (curDiv == 2 && nextDiv == 2)
            {
                lo += curDelta;
                hi += curDelta;
                if (lo > 1899)
                {
                    cout << "Impossible\n";
                    return;
                }
                lo = min(lo,1899ll);
                hi = min(hi,1899ll);
            }
            else
            if (curDiv == 2 && nextDiv == 1) //kalau naik divisi deltanya harus positif
            {
                if (curDelta <= 0)
                {
                    cout << "Impossible\n";
                    return;
                }
                lo += curDelta;
                hi += curDelta;
                if (hi < 1900) //kalau kemungkinan max + delta masih < 1900 pasti impossible
                {
                    cout << "Impossible\n";
                    return;
                }
                lo = max(lo,1900ll);
            }
            else
            if (curDiv == 1 && nextDiv == 2) //deltanya harus negatif buat turun div2
            {
                if (curDelta >= 0)
                {
                    cout << "Impossible\n";
                    return;
                }
                lo += curDelta;
                hi += curDelta;
                if (lo > 1899) //kalau kemungkinan min + delta masih >= 1900 pasti impossible
                {
                    cout << "Impossible\n";
                    return;
                }
                hi = min(hi,1899ll);
            }
            else
            {
                lo += curDelta;
                hi += curDelta;
                if (hi < 1900)
                {
                    cout << "Impossible\n";
                    return;
                }
                lo = max(lo,1900ll);
            }
            curDiv = nextDiv;
            // cout << lo << " " << hi << endl;
        }
        cout << hi + r[n] << endl;
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