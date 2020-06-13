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

int pref[1000010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ans = 0;
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        ans ^= ta;
        pref[i] = i ^ pref[i - 1];        
    }
    // cout << ans << endl;
    for (int i = 2 ; i <= n ; i++)
    {
        int tot = n / i;
        int rem = n % i;
        if (tot % 2 == 1)
        {
            ans ^= pref[i - 1];
        }
        ans ^= pref[rem];
        // cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}