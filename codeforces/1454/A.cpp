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

bool can(vector<int> &tab)
{
    for (int i = 0 ; i < tab.size() ; i++) if (tab[i] == i + 1) return false;
    return true;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> tab(n);
    for (int i = 0 ; i < n ; i++) tab[i] = i + 1;
    while (1)
    {
        if (can(tab))
        {
            for (auto it : tab)
                cout << it << " ";
            cout << endl;
            return;
        }
        shuffle(tab.begin(),tab.end(),rng);
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