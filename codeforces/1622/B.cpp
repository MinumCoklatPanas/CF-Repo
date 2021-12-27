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

void solve()
{
    int n;
    cin >> n;
    vector<int> tab(n);
    vector<int> pos(n + 5,0);
    for (int i = 0 ; i < n ; i++)
    {
        cin >> tab[i];
        pos[tab[i]] = i;
    }
    string s;
    cin >> s;
    vector<pair<int,int>> vals;
    for (int i = 0 ; i < n ; i++) if (s[i] == '1')
    {
        vals.emplace_back(tab[i],i);
    }
    sort(vals.begin(),vals.end());
    reverse(vals.begin(),vals.end());
    int cur = n;
    vector<int> ans(n,-1);
    // return;
    for (auto it : vals)
    {
        // cerr << it.second << endl;
        ans[it.second] = cur--;
    }
    
    vals.clear();
    for (int i = 0 ; i < n ; i++) if (s[i] == '0')
    {
        vals.emplace_back(tab[i],i);
    }
    sort(vals.begin(),vals.end());
    reverse(vals.begin(),vals.end());
    for (auto it : vals)
    {
        // cerr << it.second << endl;
        ans[it.second] = cur--;
    }

    for (auto it : ans) 
        cout << it << " ";
    cout << endl;
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