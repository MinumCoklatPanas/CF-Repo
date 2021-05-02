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
    int n,x;
    cin >> n >> x;
    vector<int> tab(n);
    int tot = 0;
    for (auto &it : tab) cin >> it,tot += it;
    if (tot == x)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        int sum = 0;
        for (int i = 0 ; i < n ; i++)
        {
            sum += tab[i];
            if (sum == x)
            {
                swap(tab[i],tab[i + 1]);
                assert(i != n - 1);
            }
        }
        for (auto it : tab)
            cout << it << " ";
        cout << endl;
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