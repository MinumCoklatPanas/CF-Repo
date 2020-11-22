#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

set<int> st;
set< pair<int,int> > edge;

void dfs(int u)
{
    // cout << u << endl;
    st.erase(st.find(u));
    for (auto it = st.begin() ; it != st.end() ; )
    {
        int v = *it;
        if (edge.find({min(u,v),max(u,v)}) == edge.end())
        {
            // cout << u << " " << v << endl;
            dfs(v);
        }
        it = st.upper_bound(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>> n >> m;
    for (int i = 1 ; i <= n ; i++) st.insert(i);
    for (int i = 1 ; i <= m ; i++)
    {
        int u,v;
        cin >> u >> v;
        edge.insert({min(u,v),max(u,v)});
    }
    int cc = 0;
    for (int i = 1 ; i <= n ; i++) if (st.find(i) != st.end())
    {
        // cout << i << " start\n";
        // cout << "=====================\n";
        dfs(i);
        ++cc;
        // cout << "=====================\n";
    }
    cout << cc - 1 << endl;
    return 0;
}