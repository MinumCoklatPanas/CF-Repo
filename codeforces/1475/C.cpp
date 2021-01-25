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

void solve()
{
    int a,b,k;
    cin >> a >> b >> k;
    vector<int> frekBoys(a + 5,0);
    vector<int> frekGirls(b + 5,0);
    vector< pair<int,int> > tab(k);
    map< pair<int,int>,int > frekPair;
    for (int i = 0 ; i < k ; i++) cin >> tab[i].first,frekBoys[tab[i].first]++;
    for (int i = 0 ; i < k ; i++) cin >> tab[i].second,frekGirls[tab[i].second]++;
    for (auto it : tab) 
    {
        // cout << it.first << " " << it.second << endl;
        frekPair[it]++;
    }
    int ans = 0;
    for (int i = 0 ; i < k ; i++)
    {
        auto it = tab[i];
        int boy = it.first;
        int girl = it.second;
        // cout << frekBoys[boy] << endl;
        frekPair[it]--;
        frekBoys[boy]--;
        frekGirls[girl]--;
        // cout << frekBoys[boy] << " " << frekGirls[girl] << " " << frekPair[it] << endl;
        // cout << frekPair[it] << endl;
        // ans += 
        int beda = k - (i + 1);
        beda -= frekBoys[boy];
        beda -= frekGirls[girl];
        beda += frekPair[it];
        // cout << beda << endl;
        ans += beda;
    }
    cout << ans << endl;
}

signed main()
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