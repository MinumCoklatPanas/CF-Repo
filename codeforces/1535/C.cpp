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
    string s;
    cin >> s;
    int ganjil0 = 0,ganjil1 = 0,genap0 = 0,genap1 = 0;
    int ans = 0;
    for (int i = 1 ; i <= s.length() ; i++)
    {
        if (i % 2 == 0)
        {
            if (s[i - 1] == '1')
            {
                int mx = max(genap0,ganjil1);
                ans += i - mx;
                genap1 = i;
            }
            else
            if (s[i - 1] == '0')
            {
                int mx = max(ganjil0,genap1);
                ans += i - mx;
                genap0 = i;
            }
            else
            {
                int mx = min(max(ganjil0,genap1),max(genap0,ganjil1));
                ans += i - mx;
            }
        }
        else
        {
            if (s[i - 1] == '1')
            {
                int mx = max(genap1,ganjil0);
                ans += i - mx;
                ganjil1 = i;
            }
            else
            if (s[i - 1] == '0')
            {
                int mx = max(ganjil1,genap0);
                ans += i - mx;
                ganjil0 = i;
            }
            else
            {
                int mx = min(max(ganjil1,genap0),max(genap1,ganjil0));
                ans += i - mx;
            }
        }
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