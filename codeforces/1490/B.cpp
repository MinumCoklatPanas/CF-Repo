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
    vector<int> over(3);
    over[0] = over[1] = over[2] = n / 3;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        over[ta % 3]--; 
    }
    if (over[0] == over[1] && over[1] == over[2] && over[2] == 0)
        cout << 0 << endl;
    else
    {
        int countOver = 0;
        countOver += (over[0] < 0);
        countOver += (over[1] < 0);
        countOver += (over[2] < 0);
        if (countOver == 1)
        {
            // cout << "yo";
            int ans = 0;
            for (int i = 0 ; i < 3 ; i++) if (over[i] < 0)
            {
                ans += over[(i + 1) % 3];
                ans += over[(i + 2) % 3] * 2;
            }
            cout << ans << endl;
        }
        else
        {
            int ans = 0;
            for (int i = 0 ; i < 3 ; i++) if (over[i] > 0)
            {
                ans -= over[(i + 2) % 3];
                ans -= over[(i + 1) % 3] * 2;
            }
            cout << ans << endl;
        }
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