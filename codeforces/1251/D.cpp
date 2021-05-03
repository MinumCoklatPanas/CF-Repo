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
    int n,s;
    cin >> n >> s;
    vector< pair<int,int> > tab(n);
    for (auto &it : tab) cin >> it.first >> it.second;

    const auto checkByRight = [&](int x) -> bool
    {
        sort(tab.begin(),tab.end(),[&](pair<int,int> a,pair<int,int> b)
        {
            return (a.second < b.second);
        });
        reverse(tab.begin(),tab.end());
        vector<bool> sudah(n,0);
        int cnt = 0;
        int sum = 0;
        for (int i = 0 ; i < n ; i++) if (tab[i].first >= x || tab[i].second >= x)
        {
            ++cnt;
            sum += max(tab[i].first,x);
            sudah[i] = 1;
            if (cnt * 2 > n) break;
        }
        // cout << cnt << endl;
        for (int i = 0 ; i < n ; i++) if (!sudah[i] && (tab[i].first <= x))
        {
            ++cnt;
            sum += tab[i].first;
            sudah[i] = 1;
        }
        if (cnt == n && sum <= s) return 1;
        else return 0;
    };

    const auto checkByLeft = [&](int x) -> bool
    {
        sort(tab.begin(),tab.end(),[&](pair<int,int> a,pair<int,int> b)
        {
            return (a.first < b.first);
        });
        reverse(tab.begin(),tab.end());
        vector<bool> sudah(n,0);
        int cnt = 0;
        int sum = 0;
        for (int i = 0 ; i < n ; i++) if (tab[i].first >= x || tab[i].second >= x)
        {
            ++cnt;
            sum += max(tab[i].first,x);
            sudah[i] = 1;
            if (cnt * 2 > n) break;
        }
        // cout << cnt << endl;
        for (int i = 0 ; i < n ; i++) if (!sudah[i] && (tab[i].first <= x))
        {
            ++cnt;
            sum += tab[i].first;
            sudah[i] = 1;
        }
        if (cnt == n && sum <= s) return 1;
        else return 0;
    };

    // cout << checkByRight(5) << endl;
    // exit(0);
    vector<int> lVals,rVals;
    for (int i = 0 ; i < n ; i++)
    {
        lVals.push_back(tab[i].first);
        rVals.push_back(tab[i].second);
    }
    sort(lVals.begin(),lVals.end());
    sort(rVals.begin(),rVals.end());
    int l = lVals[n / 2];
    int r = rVals[n / 2];
    while (r - l > 1)
    {
        // cout << l << " " << r << endl;
        int mid = (l + r) / 2;
        if (checkByRight(mid) || checkByLeft(mid))
            l = mid;
        else
            r = mid - 1;
    }
    if (checkByRight(r) || checkByLeft(r))
        cout << r << endl;
    else
        cout << l << endl;
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