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
    int n,m;
    cin >> n >> m;
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    vector<int> good,bad;
    for (int i = 0 ; i < n ; i++)
    {
        int ta;
        cin >> ta;
        if (ta == 1)
            bad.push_back(tab[i]);
        else
            good.push_back(tab[i]);
    }
    sort(bad.begin(),bad.end());
    sort(good.begin(),good.end());
    reverse(bad.begin(),bad.end());
    reverse(good.begin(),good.end());
    vector<int> prefBad,prefGood;
    if (bad.size() > 0)
    {
        prefBad.push_back(bad[0]);
        for (int i = 1 ; i < bad.size() ; i++)
            prefBad.push_back(prefBad.back() + bad[i]);
    }
    
    if (good.size() > 0)
    {
        prefGood.push_back(good[0]);
        for (int i = 1 ; i < good.size() ; i++)
            prefGood.push_back(prefGood.back() + good[i]);
    }
    int ans = INF;
    for (int i = 0 ; i < bad.size() ; i++)
    {
        int cur = prefBad[i];
        int rem = m - cur;
        if (rem <= 0)
        {
            ans = min(ans,i + 1);
            break;
        }
        if (prefGood.size() == 0) continue;
        int pos = lower_bound(prefGood.begin(),prefGood.end(),rem) - prefGood.begin();
        if (pos != prefGood.size())
        {
            int cost = i + 1 + ((pos + 1) * 2);
            ans = min(ans,cost);
        }
    }
    // cout << "yo\n";
    for (int i = 0 ; i < good.size() ; i++)
    {
        int cur = prefGood[i];
        int rem = m - cur;
        if (rem <= 0)
        {
            ans = min(ans,(i + 1) * 2);
            break;
        }
        if (prefBad.size() == 0) continue;
        int pos = lower_bound(prefBad.begin(),prefBad.end(),rem) - prefBad.begin();
        if (pos != prefBad.size())
        {
            int cost = ((i + 1) * 2) + pos + 1;
            ans = min(ans,cost);
        }
    }

    if (ans == INF)
        cout << -1 << endl;
    else
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