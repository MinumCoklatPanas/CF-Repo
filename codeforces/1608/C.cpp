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

vector<int> adj[100010];
int dfs_low[100010];
int dfs_num[100010];
bool vis[100010];
int VisitKe;
bool ada[100010];
stack<int> st;
int SCC_index[100010];
int SCC_count;

void reset(int n)
{
    for (int i = 0 ; i < n ; i++)
    { 
        adj[i].clear();
        ada[i] = 0;
        vis[i] = 0;
    }
    while (!st.empty()) st.pop();
    SCC_count = 0;
    VisitKe = 1;
}

void Tarjan(int u)
{
	dfs_low[u]=dfs_num[u]=VisitKe++;
	st.push(u); ada[u]=1;
	vis[u]=1;
	for (int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if (!vis[v])
		 Tarjan(v);
		if (ada[v])
		 dfs_low[u]=min(dfs_low[u],dfs_low[v]);
	}
	if (dfs_low[u]==dfs_num[u])
	{
		vector<int> tmp;
		while (st.top()!=u)
		{
			tmp.push_back(st.top());
			ada[st.top()]=0;
            SCC_index[st.top()] = SCC_count;
			st.pop();
		}
		st.pop();
		tmp.push_back(u);
        SCC_index[u] = SCC_count;
		ada[u]=0;
        SCC_count++;
	}
}

void solve()
{
    int n;
    cin >> n;
    reset(n);
    vector<pair<int,int>> a(n),b(n);
    for (int i = 0 ; i < n ; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0 ; i < n ; i++)
    {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    // for (auto it : a)
    //     cerr << it.first << " " << it.second << endl;
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    for (int i = 0 ; i + 1 < n ; i++)
    {
        adj[a[i].second].push_back(a[i + 1].second);
        adj[b[i].second].push_back(b[i + 1].second);
    }
    // cerr << a[0].second << endl;
    Tarjan(a[0].second);
    for (int i = 0 ; i < n ; i++)
    {
        cout << (SCC_index[i] == SCC_index[a[0].second]);
    }
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