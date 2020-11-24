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

void solve()
{
    int n;
    cin >> n;
    vector<int> tab(n + 5);
    vector<int> frek(n + 5, 0);
    for (int i = 1 ; i <= n ; i++) cin >> tab[i], frek[tab[i]]++;
    int mn = INF;
    for (int i = 1 ; i <= n ; i++) if (frek[i] == 1)
    {
        mn = i;
        break;
    }
    if (mn == INF)
    {
        cout << "-1\n";
        return;
    }
    for (int i = 1 ; i <= n ; i++) if (tab[i] == mn)
    {
        cout << i << endl;
        return;
    }

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