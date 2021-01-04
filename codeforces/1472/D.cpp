#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int long long
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
    priority_queue< int > even,odd;
    int tot = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        if (ta % 2 == 0)
            even.push(ta);
        else
            odd.push(ta);
        tot += ta;
    }
    int alice = 0;
    int bob = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        if (i % 2 == 1)
        {
            if ((odd.empty()) || (!even.empty() && even.top() > odd.top()))
                alice += even.top(),even.pop();
            else
            if ((even.empty()) || (!odd.empty() && odd.top() > even.top()))
                odd.pop();
        }
        else
        {
            if ((even.empty()) || (!odd.empty() && odd.top() > even.top()))
                bob += odd.top(), odd.pop();
            else
            if ((odd.empty()) || (!even.empty() && even.top() > odd.top()))
                even.pop();
        }
        
    }
    // cout << alice << " " << bob << endl;
    if (alice > bob)
        cout << "Alice\n";
    else
    if (alice < bob)
        cout << "Bob\n";
    else
        cout << "Tie\n";
}

signed main()
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