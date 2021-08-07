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

void solve()
{
    int n;
    cin >> n;
    vector<string> tab(n);
    for (auto &it : tab) cin >> it;
    vector<string> ans(n,"-");
    map<string,int> frek;
    for (int i = 0 ; i < n ; i++)
    {
        set<string> st;
        for (int len = 1 ; len <= 9 ; len++)
        {
            for (int j = 0 ; j + len - 1 < 9 ; j++)
            {
                auto cur = tab[i].substr(j,len);
                st.insert(cur);
            }
        }
        for (auto it : st)
            frek[it]++;
    }
    for (int i = 0 ; i < n ; i++)
    {
        for (int len = 1 ; len <= 9 ; len++)
        {
            for (int j = 0 ; j + len - 1 < 9 ; j++)
            {
                auto cur = tab[i].substr(j,len);
                if (frek[cur] == 1)
                {
                    ans[i] = cur;
                    goto hell;
                }
            }
        }
        hell:;
    }
    for (auto it : ans)
        cout << it << endl;
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