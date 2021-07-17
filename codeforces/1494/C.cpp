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

void solve(bool deb,int t)
{
    int n,m;
    cin >> n >> m;
    // if (deb && t == 78)
    //     cout << n << " " << m << endl;
    vector<int> aPos,aNeg,bPos,bNeg;
    for (int i = 0 ; i < n ; i++)
    {
        int ta;
        cin >> ta;
        // if (deb && t == 78)
        //     cout << ta << " ";
        if (ta > 0)
            aPos.push_back(ta);
        else
            aNeg.push_back(-ta);
    }
    // if (deb && t == 78)
    //     cout << endl;
    for (int i = 0 ; i < m ; i++)
    {
        int ta;
        cin >> ta;
        // if (deb && t == 78)
        //     cout << ta << " ";
        if (ta > 0)
            bPos.push_back(ta);
        else
            bNeg.push_back(-ta);
    }
    // if (deb && t == 78)
    //     cout << endl;
    const auto fnd = [&](int l,int r,vector<int> &a) -> int
    {
        // cerr << upper_bound(a.begin(),a.end(),r) - a.begin() << endl; 
        return upper_bound(a.begin(),a.end(),r) - lower_bound(a.begin(),a.end(),l);
    };

    const auto process = [&](vector<int> &a,vector<int> &b) -> int
    {
        vector<int> suf(a.size() + 1,0);
        int ptr = b.size() - 1;
        for (int i = a.size() - 1 ; i >= 0 ; i--)
        {
            suf[i] = suf[i + 1];
            while (ptr >= 0 && b[ptr] > a[i]) --ptr;
            if (ptr >= 0 && b[ptr] == a[i])
            {
                suf[i]++;
                --ptr;
            }
        }
        // for (int i = 0 ; i < a.size() ; i++)
        //     cerr << suf[i] << " ";
        // cerr << endl;
        int ret = 0;
        int kanan = 0;
        // cerr << fnd(6,7,b) << endl;
        // cerr << "*\n";
        for (int i = 0 ; i < b.size() ; i++) if (b[i] >= a[0])
        {
            int it = b[i];
            int cnt = upper_bound(a.begin(),a.end(),it) - a.begin();
            int l = it;
            while (kanan < a.size() && a[kanan] <= it + kanan) ++kanan;
            int r = l + kanan - 1;
            int tot = fnd(l,r,b) + suf[kanan];
            // cerr << it << " " << kanan << " " << tot << " " << l << " " << r << endl;
            ret = max(ret,tot);
        }
        return ret;
    };
    int ans = 0;
    if (aPos.size() > 0 && bPos.size() > 0) 
        ans += process(aPos,bPos);
    // cerr << ans << endl;
    // cerr << "*\n";
    // return;
    reverse(aNeg.begin(),aNeg.end());
    reverse(bNeg.begin(),bNeg.end());
    if (aNeg.size() > 0 && bNeg.size() > 0)
        ans += process(aNeg,bNeg);
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = getTC();
    for (int i = 1 ; i <= t ; i++)
    {
        solve((t == 1000),i);
    }
    return 0;
}