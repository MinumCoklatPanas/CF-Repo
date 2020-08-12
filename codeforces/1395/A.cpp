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
    ll r,g,b,w;
    cin >> r >> g >> b >> w;
    ll sum = r + g + b + w;
    bool ada = (r == 0) || (b == 0) || (g == 0);
    ll genap = (r % 2 == 0) + (g % 2 == 0) + (b % 2 == 0) + (w % 2 == 0);
    ll ganjil = (r % 2 == 1) + (g % 2 == 1) + (b % 2 == 1) + (w % 2 == 1);
    if (sum % 2 == 0)
    {
        if (genap == 4 || ganjil == 4)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    else
    {
        if (genap == 3)
            cout << "Yes\n";
        else
        if (ganjil == 3)
        {
            if (ada)    
                cout << "No\n";
            else
                cout << "Yes\n";
        }
        else
            cout << "No\n";
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