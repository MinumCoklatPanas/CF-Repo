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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int tab[3010];
int pref[3010];
map<int,bool> ada;

void solve()
{
    ada.clear();
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> tab[i];
    for (int i = 1 ; i <= n ; i++)
    {
        pref[i] = pref[i - 1] + tab[i];
        ada[pref[i]] = 1;
    }
    int tot = pref[n];
    int ans = INF;
    for (int i = 1 ; i <= n ; i++) if (tot % pref[i] == 0)
    {
        bool can = 1;
        int tmp = tot;
        while (tmp != pref[i])
        {
            if (!ada[tmp])
            {
                can = 0;
                break;
            }
            tmp -= pref[i];
        }
        if (can)
        {
            int partisi = tot / pref[i];
            ans = min(ans,n - partisi);
        }
    }
    cout << ans << endl;
}

int main()
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