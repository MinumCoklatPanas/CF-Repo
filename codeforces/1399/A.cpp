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

void solve()
{
    int n;
    cin >> n;
    vector<int> tab(n);
    for (int i = 0 ; i < n ; i++)
        cin >> tab[i];
    sort(tab.begin(),tab.end());
    for (int i = 0 ; i + 1 < n ; i++)
    {
        if (tab[i + 1] - tab[i] > 1)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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