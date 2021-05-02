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

void solve()
{
    int n,m,x;
    cin >> n >> m >> x;
    vector< pair<int,int> > tab(n);
    for (int i = 0 ; i < n ; i++)
    {
        cin >> tab[i].first;
        tab[i].second = i;
    }
    sort(tab.begin(),tab.end());
    reverse(tab.begin(),tab.end());
    bool kanan = 1;
    int curDiff = 0;
    vector<int> ans(n,-1);
    int i = 0;
    while (i < n)
    {
        int awal = i;
        for (int j = awal ; j < awal + m && j < n ; j++)
        {
            if (kanan)
                ans[tab[j].second] = j - awal + 1;
            else
                ans[tab[j].second] = m - (j - awal);
        }
        kanan ^= 1;
        i += m;
    }
    cout << "YES\n";
    for (int i = 0 ; i < n ; i++)
    {
        cout << ans[i] << " ";
        assert(ans[i] != -1);
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