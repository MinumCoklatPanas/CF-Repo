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

ll toNum(string s)
{
    stringstream ss(s);
    ll ret;
    ss >> ret;
    return ret;
}

vector<ll> nums;

ll cnt(ll l,ll r)
{
    if (l > r) return 0;
    // cout << l << " " << r << endl;
    ll ix = lower_bound(nums.begin(),nums.end(),l) - nums.begin();
    ll nxt = nums[ix];
    ll ki = l;
    ll ka = min(nxt,r);
    ll len = ka - ki + 1;
    return (len * nxt) + cnt(ka + 1,r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (ll len = 1 ; len <= 9 ; len++)
    {
        for (ll i = 0 ; i <= len ; i++)
        {
            string tmp;
            for (ll j = 1 ; j <= i ; j++)
                tmp +='4';
            for (ll j = 1 ; j <= len - i ; j++)
                tmp += '7';
            do {
                ll ret = toNum(tmp);
                nums.push_back(ret);
            } while (next_permutation(tmp.begin(),tmp.end()));
        }
    }
    nums.push_back(toNum("4444444444"));
    sort(nums.begin(),nums.end());
    ll l,r;
    cin >> l >> r;
    ll ans = cnt(l,r);
    cout << ans << endl;
    return 0;
}