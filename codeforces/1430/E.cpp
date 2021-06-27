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

int BIT[200010];

void upd(int x)
{
    for ( ; x <= 200000 ; x += (x & -x))
        BIT[x]++;
}

int query(int x)
{
    int ret = 0;
    for ( ; x ; x -= (x & -x))
        ret += BIT[x];
    return ret;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector< queue<int> > pos(26);
    for (int i = 0 ; i < n ; i++)
    {
        pos[s[i] - 'a'].push(i + 1);
    }
    reverse(s.begin(),s.end());
    vector<int> tab;
    for (int i = 0 ; i < n ; i++)
    {
        tab.push_back(pos[s[i] - 'a'].front());
        pos[s[i] - 'a'].pop();
    }
    int ans = 0;
    for (int i = 0 ; i < n ; i++)
    {
        ans += query(n) - query(tab[i]);
        upd(tab[i]);
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