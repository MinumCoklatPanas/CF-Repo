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
    if (n % 2 == 1)
        cout << "NO\n";
    else
    {
        int akar1 = (int)sqrt(n / 2);
        int akar2 = (int)sqrt(n / 4);
        if (akar1 * akar1 == (n / 2))
            cout << "YES\n";
        else
        if (akar2 * akar2 == (n / 4) && (n % 4 == 0))
            cout << "YES\n";
        else
            cout << "NO\n";
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