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
ll sum[2][100010];
vector<ll> compress;
ll n,k;

ll getSum(ll kode,ll l,ll r)
{
    return sum[kode][l] - sum[kode][r + 1];
}

bool can(ll ix,ll cur)
{
    ll tot = getSum(1,ix,cur);
    ll change = getSum(0,ix,cur) * compress[cur] - tot;    
    return (change <= k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (ll i = 1 ; i <= n ; i++)
    {
        ll ta;
        cin >> ta;
        frek[ta]++;
        compress.push_back(ta);
    }
    sort(compress.begin(),compress.end());
    compress.erase(unique(compress.begin(),compress.end()),compress.end());
    ll len = compress.size() - 1;
    ll mx = 0;
    ll ans = INFF;
    for (ll i = len ; i >= 0 ; i--)
    {
        sum[0][i] = frek[compress[i]] + sum[0][i + 1];
        sum[1][i] = frek[compress[i]] * compress[i] + sum[1][i + 1];
        // mx = max(mx,frek[compress[i]]);
        if (frek[compress[i]] > mx)
        {
            mx = frek[compress[i]];
            ans = compress[i];
        }
        else
        if (frek[compress[i]] == mx)
        {
            ans = min(ans,compress[i]);
        }
    }
    for (ll i = 1 ; i <= len ; i++)
    {
        ll l = 0;
        ll r = i;
        while (r - l > 1)
        {
            ll mid = (l + r) >> 1;
            if (can(mid,i))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        ll ix;
        if (can(l,i))
            ix = l;
        else
            ix = r;
        ll curFrek = getSum(0,ix,i);
        ll rem = k - (compress[i] * curFrek - getSum(1,ix,i));
        assert(rem >= 0);
        // cout << curFrek << endl;
        if (ix > 0)
        {
            ll diff = compress[i] - compress[ix - 1];
            curFrek += min(rem / diff,frek[compress[ix - 1]]);
        }
        // cout << curFrek << endl;
        if (curFrek > mx)
        {
            mx = curFrek;
            ans = compress[i];
        }
        else
        if (curFrek == mx)
        {
            ans = min(ans,compress[i]);
        }
    }
    assert(mx <= n);
    cout << mx << " " << ans << endl;
    return 0;
}