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
    int n;
    cin >> n;
    vector< string > tab(n);
    vector< pair<string,int> > aa,ab,ba,bb;
    map<string,int> ada;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> tab[i];
        if (tab[i][0] == '0' && tab[i].back() == '0')
        {
            aa.push_back({tab[i],i});
        }
        if (tab[i][0] == '0' && tab[i].back() == '1')
        {
            ab.push_back({tab[i],i});
        }
        if (tab[i][0] == '1' && tab[i].back() == '0')
        {
            ba.push_back({tab[i],i});
        }
        if (tab[i][0] == '1' && tab[i].back() == '1')
        {
            bb.push_back({tab[i],i});
        }
        ada[tab[i]] = 1;
    }
    if ((aa.size() > 0 && bb.size() > 0) && (ab.size() == 0 && ba.size() == 0))
    {
        cout << -1 << endl;
        return;
    }
    int need = 0;
    vector<int> used;
    if (ab.size() > ba.size() + 1)
    {
        need = (ab.size() - ba.size()) / 2;
        for (auto it : ab)
        {
            string tmp = it.first;
            reverse(tmp.begin(),tmp.end());
            if (!ada[tmp])
                used.push_back(it.second);
        }
    }
    else
    if (ba.size() > ab.size() + 1)
    {
        need = (ba.size() - ab.size()) / 2;
        for (auto it : ba)
        {
            string tmp = it.first;
            reverse(tmp.begin(),tmp.end());
            if (!ada[tmp])
                used.push_back(it.second);
        }
    }
    cout << need << endl;
    for (int i = 0 ; i < need ; i++)
        cout << used[i] + 1 << " ";
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