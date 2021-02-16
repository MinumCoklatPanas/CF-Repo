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

void rec(int l,int r,vector< vector<int> > &mx, vector<int> &ans,int depth)
{
    // cout << l << " " << r << " " << mx[l][r] << endl;
    if (l > r) return;
    int maxIx = mx[l][r];
    ans[maxIx] = depth;
    rec(l,maxIx - 1,mx,ans,depth + 1);
    rec(maxIx + 1,r,mx,ans,depth + 1);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    vector< vector<int> > mx(n,vector<int>(n,-1));
    for (int i = 0 ; i < n ; i++) mx[i][i] = i;
    for (int i = 2 ; i <= n ; i++)
    {
        for (int j = 0 ; j + i - 1 < n ; j++)
        {
            int l = j;
            int r = j + i - 1;
            int bef = mx[l][r - 1];
            if (tab[r] > tab[bef])
                mx[l][r] = r;
            else
                mx[l][r] = bef;
        }   
    }
    // cout << mx[0][4] << endl;
    // return; 
    vector<int> ans(n,-1);
    rec(0,n - 1,mx,ans,0);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}