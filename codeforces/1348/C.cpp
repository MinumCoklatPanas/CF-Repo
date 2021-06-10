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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    if (s[0]< s[k - 1])
    {
        cout << s[k - 1] << endl;
    }
    else
    {
        bool sama = 1;
        for (int i = k ; i < n ; i++) sama &= (s[i] == s[k]);
        if (!sama)
        {
            cout << s[0];
            for (int i = k ; i < n ; i++) cout << s[i];
            cout << endl;
        }
        else
        {
            const auto cei = [&](int x,int y) -> int
            {
                return ((x / y) + (x % y != 0));
            };
            int sisa = cei(n - k,k);
            cout << s[0];
            for (int i = 1 ; i <= sisa ; i++) cout << s[k];
            cout << endl;

        }
    }
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