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

int tab[200010];
int ans[200010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tot = 0;
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
        tot ^= tab[i];
    }
    for (int i = 1 ; i <= n ; i++)
        ans[i] = tot ^ tab[i];
    for (int i = 1 ; i <= n ; i++)
    {
        if (i == n)
            cout << ans[i] << endl;
        else
            cout << ans[i] << " ";
    }
    return 0;
}