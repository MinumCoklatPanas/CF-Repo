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

map<int,bool> ada;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x,n;
    cin >> x >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        ada[ta] = 1;
    }
    int mn = INF;
    int ans = INF;
    for (int i = -1000 ; i <= 1000 ; i++) if (!ada[i])
    {
        int diff = abs(i - x);
        if (mn == diff)
        {
            ans = min(ans,i);
        }
        else
        if (diff < mn)
        {
            ans = i;
            mn = diff;
        }
    }
    cout << ans << endl;
    return 0;
}