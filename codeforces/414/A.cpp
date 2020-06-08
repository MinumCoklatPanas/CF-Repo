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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll ans[100010];
map<ll,ll> ada;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin >> n >> k;
    if (n == 1)
    {
        if (k == 0)
            cout << 1 << endl;
        else
            cout << -1 << endl;
        return 0;
    }
    ll mn = n / 2;
    if (k < mn)
        cout << -1 << endl;
    else
    {
        // cout << mn << endl;
        ll r = k;
        ans[1] = k - (mn - 1);
        ans[2] = 2 * (k - (mn - 1));
        r -= __gcd(ans[1],ans[2]);
        assert(r == mn - 1);
        for (ll i = 3 ; i < n ; i += 2)
        {
            while (1)
            {
                ll a = 1 + rng() % INF;
                ll b = 1 + rng() % INF;    
                if (ada.count(a) || ada.count(b)) continue;
                if (__gcd(a,b) == 1)
                {
                    ans[i] = a;
                    ans[i + 1] = b;
                    ada[a] = 1;
                    ada[b] = 1;
                    break;
                }
            }
            r -= __gcd(ans[i],ans[i + 1]);
            assert(r >= 0);
        }
        assert(r == 0);
        if (n & 1)
        {
            ll tmp = 1 + rng() % INF;
            while (ada.count(tmp))
            {
                tmp = 1 + rng() % INF;
            }
            ans[n] = tmp;
        }
        // if (cnt != k)
        // {
        //     cout << cnt << " " << k << endl;
        // }
        for (ll i = 1 ; i <= n ; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    
    return 0;
}