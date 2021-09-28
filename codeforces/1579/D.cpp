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
    set<pair<int,int>> st;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        if (ta > 0)
            st.insert({-ta,i});
    }
    vector<pair<int,int>> ans;
    while (st.size() > 1)
    {
        auto it = st.begin();
        auto satu = *it;
        ++it;
        auto dua = *it;
        // cerr << satu.first << " " << satu.second << endl;
        // cerr << dua.first << " " << dua.second << endl;
        // cerr << endl;
        ans.push_back({satu.second,dua.second});
        st.erase(st.begin());
        st.erase(st.begin());
        ++satu.first;
        ++dua.first;
        if (satu.first != 0)
            st.insert(satu);
        if (dua.first != 0)
            st.insert(dua);
    }
    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it.first << " " << it.second << endl;
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