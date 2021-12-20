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

struct query
{
    int tipe;
    int x,y;
    query(){}
    query(int _tipe,int _x,int _y)
    {
        tipe = _tipe;
        x = _x;
        y = _y;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> change(500010);
    vector<query> tab(n);
    for (int i = 0 ; i < n ; i++)
    {
        query it;
        cin >> it.tipe >> it.x;
        if (it.tipe == 2)
        {
            cin >> it.y;
            if (it.x != it.y)
                change[it.x].push_back({i,it.y});
        }
        tab[i] = it;
    }
    vector<map<int,int>> vis(500010);
    const auto dfs = [&](const auto &self,int tim,int num) -> int
    {
        if (vis[num].count(tim)) return vis[num][tim];
        int pos = lower_bound(change[num].begin(),change[num].end(),make_pair(tim,-INF)) - change[num].begin();
        // cerr << tim << " " << num << " " << change[num].size() << " " << pos << endl;
        if (pos == change[num].size()) 
        {
            // cerr << num << endl;
            return vis[num][tim] = num;
        }
        else 
        {
            int hehe = self(self,change[num][pos].first,change[num][pos].second);
            return vis[num][tim] = hehe;
        }
    };  
    vector<int> ans;
    for (int i = 0 ; i < n ; i++) if (tab[i].tipe == 1)
    {
        int pos = lower_bound(change[tab[i].x].begin(),change[tab[i].x].end(),make_pair(i,-INF)) - change[tab[i].x].begin();
        if (pos == change[tab[i].x].size())
            ans.push_back(tab[i].x);
        else
        {
            int tim = change[tab[i].x][pos].first;
            int ubah = dfs(dfs,tim,tab[i].x);
            // cerr << ubah << " ubah\n";
            ans.push_back(ubah);
            // return;
        }
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