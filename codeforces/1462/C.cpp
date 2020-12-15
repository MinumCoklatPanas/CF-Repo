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

void solve(int x)
{
    // int x;
    // cin >> x;
    if (x > 45)
    {
        cout << -1 << endl;
        return;
    }
    string ans;
    int cur = 9;
    while (x > cur)
    {
        ans = (char)(cur + '0') + ans;
        x -= cur;
        --cur;
    }
    if (x > 0)
        ans = (char)(x + '0') + ans;
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // for (int i = 1 ; i <= 50 ;i++)
    // {
    //     cout << i << " ";
    //     solve(i);
    // } 
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        solve(x);
    }
    return 0;
}