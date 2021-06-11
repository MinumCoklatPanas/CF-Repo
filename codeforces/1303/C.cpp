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
    string s;
    cin >> s;
    if (s.length() == 1)
    {
        cout << "YES\n";
        for (char i = 'a' ; i <= 'z' ; i++)
            cout << i;
        cout << endl;
        return;   
    }
    vector< set<int> > adj(26);
    const auto get = [&](char x) -> int 
    {
        return x - 'a';
    };
    for (int i = 0 ; i + 1 < s.length() ; i++)
    {
        int a = get(s[i]);
        int b = get(s[i + 1]);
        adj[a].insert(b);
        adj[b].insert(a);
    }
    int start = -1;
    int cnt = 0;
    for (int i = 0 ; i < 26 ; i++)
    {
        if (adj[i].size() > 2)
        {
            cout << "NO\n";
            return;
        }
        if (adj[i].size() == 1)
        {
            ++cnt;
            start = i;
        }
    }
    if (start == -1)
        cout << "NO\n";
    else
    if (cnt != 2)
        cout << "NO\n";
    else
    {
        int cur = start;
        string ans;
        while (adj[cur].size() > 0)
        {
            ans += 'a' + cur;
            int nxt = *adj[cur].begin();
            adj[cur].erase(nxt);
            adj[nxt].erase(cur);
            cur = nxt;
        }
        ans += 'a' + cur;
        for (char i = 'a' ; i <= 'z' ; i++)
        {
            bool ada = 0;
            for (auto it : s) if (it == i)
            {
                ada = 1;
                break;
            }
            if (!ada)
                ans += i;
        }

        cout << "YES\n";
        assert(ans.size() == 26);
        cout << ans << endl;
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