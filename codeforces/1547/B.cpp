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

int n;
string s;

bool rec(int l,int r,char cur)
{
    if (l == 0 && r == n - 1) return true;
    bool ret = 0;
    if (l > 0 && s[l - 1] == cur + 1)
        ret = rec(l - 1,r,cur + 1);
    else
    if (r + 1 <= n - 1 && s[r + 1] == cur + 1)
        ret = rec(l,r + 1,cur + 1);
    return ret;
}

void solve()
{
    cin >> s;
    n = s.length();
    vector<int> frek(26,0);
    for (int i = 0 ; i < n ; i++) frek[s[i] - 'a']++;
    for (int i = 0 ; i < 26 ; i++) if (frek[i] > 1)
    {
        cout << "NO\n";
        return;
    }
    bool can = 0;
    for (int i = 0 ; i < n ; i++) if (s[i] == 'a')
    {
        can = rec(i,i,'a');
    }   
    if (can)
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