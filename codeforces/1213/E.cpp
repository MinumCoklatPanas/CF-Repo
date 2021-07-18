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
    string a,b;
    cin >> a >> b;
    vector<char> tab = {'a','b','c'};
    do
    {
        string ans;
        for (auto it : tab)
        {
            for (int i = 1 ; i <= n ; i++)
                ans += it;
        }
        bool can = 1;
        for (int i = 0 ; i + 1 < ans.length() ; i++)
        {
            string tmp;
            tmp += ans[i];
            tmp += ans[i + 1];
            if (tmp == a || tmp == b)
            {
                can = 0;
                break;
            }
        }
        if (can)
        {
            cout << "YES\n";
            cout << ans << endl;
            return;
        }
        ans = "";
        for (int i = 0 ; i < n ; i++)
        {
            ans += tab[0];
            ans += tab[1];
            ans += tab[2];
        }
        can = 1;
        for (int i = 0 ; i + 1 < ans.length() ; i++)
        {
            string tmp;
            tmp += ans[i];
            tmp += ans[i + 1];
            if (tmp == a || tmp == b)
            {
                can = 0;
                break;
            }
        }
        if (can)
        {
            cout << "YES\n";
            cout << ans << endl;
            return;
        }
    } while (next_permutation(tab.begin(),tab.end()));
    
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