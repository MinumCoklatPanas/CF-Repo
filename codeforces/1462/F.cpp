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

map<int,int> mp;
int startWith[400010];
int endWith[400010];

void solve()
{
    mp.clear();
    int n;
    cin >> n;
    for (int i = 1 ; i <= 2 * n ; i++)
    {
        startWith[i] = 0;
        endWith[i] = 0;
    }
    vector< pair<int,int> > tab;
    vector<int> val;
    for (int i = 1 ; i <= n ; i++)
    {
        int a,b;
        cin >> a >> b;
        tab.push_back({a,b});
        val.push_back(a);
        val.push_back(b);
    }
    sort(val.begin(),val.end());
    val.erase(unique(val.begin(),val.end()),val.end());
    // for (auto it : val)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;
    for (int i = 0 ; i < val.size() ; i++)
        mp[val[i]] = i + 1;
    for (int i = 0 ; i < n ; i++)
    {
        tab[i].first = mp[tab[i].first];
        tab[i].second = mp[tab[i].second];
        // cout << tab[i].first << " " << tab[i].second << endl;
        startWith[tab[i].first]++;
        endWith[tab[i].second]++;
    }
    for (int i = 1 ; i <= 2 * n ; i++)
    {
        startWith[i] += startWith[i - 1];
        endWith[i] += endWith[i - 1];
    }
    int ans = INF;
    for (int i = 0 ; i < n ; i++)
    {
        int l = tab[i].first;
        int r = tab[i].second;
        int kiri = endWith[l - 1];
        int kanan = startWith[2 * n] - startWith[r];
        ans = min(ans,kiri + kanan);
    }
    cout << ans << endl;
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