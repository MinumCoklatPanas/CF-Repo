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
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    bool is_sorted = 1;
    for (int i = 1 ; i < n ; i++)
    {
        if (tab[i] < tab[i - 1]) is_sorted = 0;
    }
    bool is_desc = 1;
    for (int i = 1 ; i < n ; i++)
    {
        if (tab[i] > tab[i - 1]) is_desc = 0;
    }
    if (is_sorted)
        cout << 0 << endl;
    else
    if (tab[0] == 1 || tab[n - 1] == n)
    {
        cout << 1 << endl;    
    }
    else
    if (tab[0] == n && tab[n - 1] == 1)
    {
        cout << 3 << endl;
    }
    else
    {
        cout << 2 << endl;
    }
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