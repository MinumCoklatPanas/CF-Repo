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

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<char,int>> tab;
    tab.emplace_back(s[0],1);
    for (int i = 1 ; i < n ; i++)
    {
        if (s[i] == tab.back().first)
            ++tab.back().second;
        else
            tab.emplace_back(s[i],1);
    }
    set<int> st;
    for (int i = 0 ; i < tab.size() ; i++) if (tab[i].second > 1)
        st.insert(i);
    // for (auto it : st)
    //     cerr << it.first << " " << it.second << endl;
    int ans = 0;
    for (int i = 0 ; i < tab.size() ; i++)
    {
        ++ans;
        if (st.size() > 0)
        {
            int ix = *(st.begin());
            --tab[ix].second;
            if (ix == i || tab[ix].second == 1)
                st.erase(ix);
        }
        else
            ++i;

    }
    cout << ans << endl;
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