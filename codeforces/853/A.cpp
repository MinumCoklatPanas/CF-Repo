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
#define int long long

int tmp[300010];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector< pair<int,int> > tab;
    int n,k;
    cin >> n >> k;
    set<int> st;
    int ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        tab.push_back({-ta,-i});
        st.insert(i + k);
        ans -= i * ta;
    }
    sort(tab.begin(),tab.end());
    for (auto it : tab)
    {
        int cost = -it.first;
        int ix = -it.second;
        auto nxt = st.lower_bound(ix);
        if (nxt == st.end()) assert(false);
        ans += *nxt * cost;
        tmp[ix] = *nxt;
        st.erase(nxt);
    }
    cout << ans << endl;
    for (int i = 1 ; i <= n ; i++)
        cout << tmp[i] << " ";
    cout << endl;
    return 0;
}