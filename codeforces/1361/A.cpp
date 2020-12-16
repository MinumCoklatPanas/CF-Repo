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

vector<int> adj[500010];
int tab[500010];
vector<int> urutan[500010];

bool cekMEX(vector<int> &v,int k)
{
    sort(v.begin(),v.end());
    int ret = 1;
    for (auto it : v)
    {
        if (it == ret) ++ret;
    }
    return (ret == k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        urutan[ta].push_back(i);
    }
    vector<int> ans;
    for (int i = 1 ; i <= n ; i++)
    {
        for (auto it : urutan[i])
        {
            vector<int> v;
            for (auto it2 : adj[it]) if (tab[it2])
                v.push_back(tab[it2]);
            if (cekMEX(v,i))
            {
                ans.push_back(it);
                tab[it] = i;
            }
            else
            {
                if (n == 100)
                {
                    for (auto it : v)
                        cout << it << " ";
                    cout << endl;
                }
                cout << "-1\n";
                return 0;
            }
        }
    }
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}