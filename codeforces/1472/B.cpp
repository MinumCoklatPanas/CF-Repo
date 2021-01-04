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

int tab[110];

void solve()
{
    int n;
    cin >> n;
    int satu = 0;
    int dua = 0;
    int tot = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        if (ta == 1) ++satu;
        else ++dua;
        tot += ta;
    }
    if (tot % 2 == 1)
    {
        cout << "NO\n";
        return;
    }
    for (int i = 0 ; i <= satu ; i++)
    {
        int res = (tot / 2) - i;
        if (res < 0) break;
        if (res % 2 == 0)
        {
            if (res / 2 <= dua)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    // if ((satu % 2 == 0) && (dua % 2 == 0))
    //     cout << "YES\n";
    // else
        cout << "NO\n";
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