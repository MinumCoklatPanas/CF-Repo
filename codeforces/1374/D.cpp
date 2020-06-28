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

map<ll,ll> frek;
ll tab[200010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        frek.clear();
        ll n,k;
        cin >> n >> k;
        ll mx = 0;
        for (ll i = 1 ; i <= n ; i++)
        {
            cin >> tab[i];
            if (tab[i] % k != 0)
            {
                frek[k - (tab[i] % k)]++;
                mx = max(mx,frek[k - (tab[i] % k)]);
            }
        }
        if (mx == 0)
        {
            cout << 0 << endl;
            continue;
        }
        ll ans = (mx - 1) * k;
        ll mx2 = 0;
        for (auto it : frek) if (it.second == mx)
        {
            mx2 = max(mx2,it.first);            
        }
        ans += mx2;
        cout << ans + 1 << endl;
    }
    return 0;
}