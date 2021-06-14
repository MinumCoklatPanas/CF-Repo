// time-limit: 3000
// problem-url: https://codeforces.com/contest/1534/problem/D
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

int n;
vector<int> ask(int x)
{
    cout << "? " << x << endl;
    vector<int> ret;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        ret.push_back(ta);
    }
    return ret;
}

void solve()
{
    cin >> n;
    vector<int> depth(n,INF);
    vector<int> par(n + 1,-1);
    vector<int> distFromRoot = ask(1);
    vector<vector<int>> depthElement(n);
    vector<bool> dahParent(n + 1,0),dahChild(n + 1,0);
    int maxDepth = 0;
    for (int i = 0 ; i < n ; i++)
    {
        depth[i] = distFromRoot[i];
        depthElement[distFromRoot[i]].push_back(i);
        if (depth[i] == 1)
            par[i + 1] = 1;
        maxDepth = max(maxDepth,depth[i]);
    }
    dahParent[0] = 1;
    dahChild[0] = 1;
    dahParent[1] = 1;
    dahChild[maxDepth] = 1;
    priority_queue< pair<int,int> > pq;
    int sumGanjil = 0,sumGenap = 1;
    for (int i = 1 ; i <= maxDepth ; i++)
    {
        if (i & 1)
            sumGanjil += depthElement[i].size();
        else
            sumGenap += depthElement[i].size();
    }
    int start;
    if (sumGanjil < sumGenap)
        start = 1;
    else
        start = 2;
    for (int i = start ; i <= maxDepth ; i += 2)
    {
        int curDepth = i;
        for (auto it : depthElement[curDepth])
        {
            vector<int> curDist = ask(it + 1);
            // for (auto it : curDist) cerr << it << " ";
            // cerr << endl;
            for (int j = 0 ; j < n ; j++) if (curDist[j] == 1)
            {
                // cerr << j << " " << depth[j] << endl;
                if (depth[j] < curDepth)
                    par[it + 1] = j + 1;
                else
                    par[j + 1] = it + 1;
            }
        }
    }
    cout << "!" << endl;
    for (int i = 2 ; i <= n ; i++)
        cout << i << " " << par[i] << endl;
}

signed main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t = getTC();
    while (t--)
    {
        solve();
    }
    return 0;
}