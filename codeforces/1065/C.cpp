#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXN = 200000;
const ll INF = 1e18;

ll frek[MAXN + 10];
ll pref[MAXN + 10];
ll prefMul[MAXN + 10];
ll n,k;
ll tot = 0ll;

ll getCost(int v,int mn)
{
    ll sum = prefMul[v] - prefMul[mn - 1];
    ll blocks = pref[v] - pref[mn - 1];
    ll sisa = tot - sum;
    ll sisaBlock = n - blocks;
    ll cost = sisa - (v * sisaBlock);
    return cost;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll mn = INF;
	ll mx = -INF;
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++)
	{
		ll a;
		cin >> a;
		frek[a]++;
		tot += a;
		mn = min(mn,a);
		mx = max(mx,a);
	}
    for (int i = 1 ; i <= MAXN ; i++)
    {
        pref[i] = pref[i - 1] + frek[i];
        prefMul[i] = prefMul[i - 1] + (frek[i] * i);
    }
	ll ans = 0ll;
	while (mn != mx)
	{
		ll l = mn;
        ll r = mx;
        while (r - l > 1)
        {
            ll mid = (l + r) >> 1;
            ll cost = getCost(mid,mn);
            if (cost <= k)
                r = mid;
            else
                l = mid + 1;
        }
        if (getCost(l,mn) <= k)
        {
            ll sum = prefMul[l] - prefMul[mn - 1];
            ll blocks = pref[l] - pref[mn - 1];
            ll sisa = tot - sum;
            ll sisaBlock = n - blocks;
            ll cost = sisa - (l * sisaBlock);
            tot -= cost;
            frek[l] += sisaBlock;
            ans++;
            mx = l;
        }
        else
        {
            ll sum = prefMul[r] - prefMul[mn - 1];
            ll blocks = pref[r] - pref[mn - 1];
            ll sisa = tot - sum;
            ll sisaBlock = n - blocks;
            ll cost = sisa - (r * sisaBlock);
            tot -= cost;
            frek[r] += sisaBlock;
            ans++;
            mx = r;
        }
	}
	cout << ans << endl;
}