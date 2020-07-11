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

ll mul(ll x,ll y,ll m)
{
     if (m == 0) return 0;   
    return ((x % m) * (y % m)) % m;
}

ll add(ll x,ll y,ll m)
{
    if (m == 0) return 0;
    return ((x % m) + (y % m)) % m;
}

ll sub(ll x,ll y,ll m)
{
    if (m == 0) return 0;
    ll ret = ((x % m) - (y % m)) % m;
    if (ret < 0)
        ret += m;
    return ret;
}

string toBit(ll x)
{
    string ret;
    while (x)
    {
        ret += (x % 2) + '0';
        x /= 2;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

map<ll,ll> memo;

ll rec2(ll x)
{
    if (x == 0) return 0;
    if (memo.count(x)) return memo[x];
    ll tmp = x % __builtin_popcount(x);
    // cout << tmp << endl;
    return memo[x] = 1 + rec2(tmp);
}

ll rec(string s)
{
    ll cnt = 0;
    for (ll i = 0 ; i < s.length() ; i++)
        cnt += (s[i] == '1');
    ll pengali = 1;
    ll mod = 0;
    for (ll i = s.length() - 1 ; i >= 0 ; i--)
    {
        if (s[i] == '1')
        {
            mod = add(mod,pengali,cnt);
        }
        pengali = mul(pengali,2ll,cnt);
    }
    return mod;
    // cout << mod << endl;
    ll ans = 1 + rec2(mod);
    return ans;
}

ll sumMod(string s,ll m)
{
    if (m == 0) return 0;
    ll pengali = 1;
    ll mod = 0;
    for (ll i = 0 ; i < s.length() ; i++)
    {
        if (s[i] == '1')
        {
            mod = add(mod,pengali,m);
        }
        pengali = mul(pengali,2ll,m);
    }
    return mod;   
}

ll pangkatAtas[200010];
ll pangkatBawah[200010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cout << rec("00100111001011011001110") << endl;
    // cout << rec2(1283790) << endl;
    // return 0;
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll cnt = 0;
    for (int i = 0 ; i < s.length() ; i++)
        cnt += (s[i] == '1');
    // cout << cnt << endl;
    reverse(s.begin(),s.end());
    pangkatAtas[0] = pangkatBawah[0] = 1;
    for (int i = 1 ; i <= n ; i++)
    {
        pangkatAtas[i] = mul(pangkatAtas[i - 1],2ll,cnt + 1);
        // cout << pangkatAtas[i] << " ";
        pangkatBawah[i] = mul(pangkatBawah[i - 1],2ll,cnt - 1);
    }
    // cout << cnt - 1 << endl;
    // cout << endl;
    ll atas = sumMod(s,cnt + 1);
    ll bawah = sumMod(s,cnt - 1);
    // cout << atas << " " << bawah << endl;
    // cout << bawah << endl;
    vector< ll > ret;
    // cout << atas << endl;
    for (int i = 0 ; i < s.length() ; i++)
    {
        if (s[i] == '0')
        {
            // cout << "yo\n";
            ll cur = add(atas,pangkatAtas[i],cnt + 1);
            // cout << cur << endl;
            ll ans = rec2(cur) + 1;
            ret.push_back(ans);
            // cout << ans << endl;
        }
        else
        {
            if (cnt - 1 == 0)
                ret.push_back(0);
            else
            {
                ll cur = sub(bawah,pangkatBawah[i],cnt - 1);
                ll ans = rec2(cur) + 1;
                ret.push_back(ans);
                // cout << ans << endl;
            }
        }
    }
    reverse(ret.begin(),ret.end());
    for (auto it : ret)
        cout << it << endl;
    return 0;
}