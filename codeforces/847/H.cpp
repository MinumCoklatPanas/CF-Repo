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

ll tab[100010];
ll costKiri[100010];
ll costKanan[100010];
ll minKiri[100010];
ll minKanan[100010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    for (ll i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
        minKanan[i] = tab[i];
    }
    for (ll i = n - 1 ; i >= 1 ; i--)
    {
        costKanan[i] = costKanan[i + 1];
        minKanan[i] = tab[i];
        if (tab[i] <= minKanan[i + 1])
        {
            costKanan[i] += minKanan[i + 1] + 1 - tab[i];
            minKanan[i] = minKanan[i + 1] + 1;
        }
    }
    ll ans = INFF;
    for (ll i = 1 ; i <= n ; i++)
    {
        minKiri[i] = tab[i];
        costKiri[i] = costKiri[i - 1];
        if (tab[i] <= minKiri[i - 1])
        {
            // cout << i << " yo\n";
            costKiri[i] += minKiri[i - 1] + 1 - tab[i];
            minKiri[i] = minKiri[i - 1] + 1; 
        }
        ll cnt = costKiri[i] + costKanan[i + 1];
        if (minKanan[i + 1] >= minKiri[i])
        {
            cnt += minKanan[i + 1] + 1 - minKiri[i];
        }
        // cout << i << ": " << costKiri[i] << " " << costKanan[i + 1] << " " << cnt << endl;
        ans = min(ans,cnt);
    }
    cout << ans << endl;
    return 0;
}