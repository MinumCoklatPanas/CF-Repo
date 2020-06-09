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

int tab[100010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
        sum += tab[i];
    }
    // cout << sum << endl;
    if (sum % 2 != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        int tot = 0;
        int ans = 0;
        for (int i = 1 ; i < n  ; i++)
        {
            tot += tab[i];
            if (tot * 2 == sum)
            {  
                // cout << i << " ";
                ++ans;
            }
        }
        // cout << endl;
        cout << ans << endl;
    }
    return 0;
}