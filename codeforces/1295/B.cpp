#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

ll bal[100010];

ll sign(ll x)
{
    if (x < 0) return -1;
    if (x >= 0) return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n,x;
        cin >> n >> x;
        for (ll i = 1 ; i <= n ; i++)
        {
            char ta;
            cin >> ta;
            if (ta == '0')
                bal[i] = 1;
            else
                bal[i] = -1;
            bal[i] += bal[i - 1];
        }
        // for (int i = 1 ; i <= n ; i++)
        //     cout << bal[i] << " ";
        // cout << endl;
        if (bal[n] == 0)
        {
            bool ada = 0;
            for (ll i = 1 ; i <= n ; i++) if (bal[i] == x)
            {
                ada = 1;
                break;
            }
            if (ada)
                cout << -1 << endl;
            else
                cout << 0 << endl;
        }
        else
        {
            ll ans = 0;
            for (ll i = 1 ; i <= n ; i++)
            {
                ll tmp = x - bal[i];
                if (tmp % bal[n] == 0)
                {
                    int k = tmp / bal[n];
                    if (k >= 0)
                        ++ans;
                }
            }
            cout << ans + (x == 0) << endl;
        }
    }
    return 0;
}