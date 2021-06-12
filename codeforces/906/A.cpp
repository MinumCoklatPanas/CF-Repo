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
    set<int> st;
    set<int> bukan;
    for (char i = 'a' ; i <= 'z' ; i++) st.insert(i);
    int ans = 0;
    for (int i = 1 ; i < n ; i++)
    {
        char type;
        string s;
        cin >> type >> s;
        if (type == '!')
        {
            if (st.size() == 1) ++ans;
            if (st.size() == 0)
            {
                for (auto it : s) st.insert(it);
            }
            else
            {
                set<int> newSt;
                for (auto it : s)
                {
                    if (st.find(it) != st.end())
                        newSt.insert(it);
                    else
                        bukan.insert(it);
                }
                assert(newSt.size() > 0);
                st = newSt;
            }
        } 
        else
        if (type == '?')
        {
            ans += (st.size() == 1);
            bukan.insert(s[0]);
        }
        else
        {
            for (auto it : s) bukan.insert(it);
        }
        for (auto it : bukan)
        {
            if (st.find(it) != st.end()) st.erase(st.find(it));
        }
        // cerr << i << " " << st.size() << endl;
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