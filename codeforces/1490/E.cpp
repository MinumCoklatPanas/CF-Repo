#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int ll
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
    int n;
    cin >> n;
    vector<pair<int,int>> tab(n);
    ll sum = 0;
    for (int i = 0 ; i < n ; i++)
    {
        int it;
        cin >> it;
        sum += it;
        tab[i] = {it,i};
    }
    sort(tab.begin(),tab.end());
    reverse(tab.begin(),tab.end());
    if (tab[0].first == tab[n - 1].first)
    {
        cout << n << endl;
        for (int i = 1 ; i <= n ; i++)
            cout << i << " ";
        cout << endl;
        return;
    }
    vector<int> ans;
    for (int i = 0 ; i < n ; i++)
    {
        if ((i == 0) || (tab[i - 1].first <= sum))
        {
            // cout << tab[i].first << " " << tab[i].second << endl;
            ans.push_back(tab[i].second + 1);
            sum -= tab[i].first;
        }
        else
            break;
    }
    cout << ans.size() << endl;
    sort(ans.begin(),ans.end());
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
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