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

vector<int> occ;

struct cmp
{
    bool operator() (pair<int,int> a,pair<int,int> b)
    {
        return occ[a.first] < occ[b.first];
    }
};


void solve()
{
    int n,m;
    cin >> n >> m;
    occ.clear();
    occ.resize(n,0);
    vector<int> frek(n,0);
    vector<vector<int>> tab(m);
    for (int i = 0 ; i < m ; i++)
    {
        int k;
        cin >> k;
        for (int j = 0 ; j < k ; j++)
        {
            int ta;
            cin >> ta;
            --ta;
            tab[i].push_back(ta);
            frek[ta]++;
        }
    }
    vector<int> ans(m,-1);
    for (int i = 0 ; i < m ; i++)
    {
        int mx = INF;
        int take = -1;
        for (auto it : tab[i])
        {
            if (occ[it] < mx)
            {
                mx = occ[it];
                take = it;
            }
        }
        occ[take]++;
        ans[i] = take;
    }
    // for (auto it : ans)
    //     cerr << it << " ";
    // cerr << endl;
    int maxTaken = max_element(occ.begin(),occ.end()) - occ.begin();
    const auto cei = [](int x,int y) -> int
    {
        return (x / y) + (x % y != 0);
    };
    // cerr << occ[maxTaken] << endl;
    while (occ[maxTaken] > cei(m,2))
    {
        bool changed = 0;
        for (int i = 0 ; i < m ; i++) if (ans[i] == maxTaken && occ[maxTaken] > cei(m,2))
        {
            // cerr << i << " " << occ[maxTaken] << endl;
            int mn = INF;
            int take = -1;
            for (auto it : tab[i]) 
            {
                if (occ[it] < mn || (occ[it] == mn && frek[it] < frek[take]))
                {
                    mn = occ[it];
                    take = it;
                }
            }
            if ((occ[take] + 1) <= cei(m,2))
            {
                changed = 1;
                ans[i] = take;
                occ[take]++;
                occ[maxTaken]--;
            }
        }
        if(!changed) break;
        maxTaken = max_element(occ.begin(),occ.end()) - occ.begin();
    }
    int maxOcc = *max_element(occ.begin(),occ.end());
    if (maxOcc > cei(m,2))
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        for (auto it : ans)
            cout << it + 1 << " ";
        cout << endl;
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