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
    int n,k;
    cin >> n >> k;
    vector<int> tab(n);
    vector<int> frek(1000001,0);
    for (auto &it : tab)
    {
        cin >> it;
        frek[it]++;
    }
    set<int> st;
    for (int i = 1 ; i <= 1000000 ; i++) if (i != k && frek[i] >= frek[k]) 
        st.insert(i);
    for (int i = n - 1 ; i >= 0 ; i--)
    {
        --frek[tab[i]];
        if (frek[tab[i]] < frek[k])
        {
            if (st.find(tab[i]) != st.end())
            {
                st.erase(st.find(tab[i]));
            }
        }
    }
    if (st.empty())
        cout << -1 << endl;
    else
        cout << *st.begin() << endl;
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