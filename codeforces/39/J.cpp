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
const ll PRIME = 37;

ll mul(ll x,ll y)
{
    return ((x % MOD) * (y % MOD)) % MOD;
}

ll add(ll x,ll y)
{
    return ((x % MOD) + (y % MOD)) % MOD;
}

ll hashDepan[2][1000010];
ll hashBelakang[2][1000010];

void calcHash(string s,ll len,ll kode)
{
    ll cur = 0;
    ll pengali = 1;
    for (ll i = 0 ; i < len ; i++)
    {
        ll ix = s[i] - 'a' + 1;
        cur = add(cur,mul(ix,pengali));
        hashDepan[kode][i] = cur;
        pengali = mul(pengali,PRIME);
    }
    cur = 0;
    pengali = 1;
    for (ll i = len - 1 ; i >= 0 ; i--)
    {
        ll ix = s[i] - 'a' + 1;
        cur = add(cur,mul(ix,pengali));
        hashBelakang[kode][i] = cur;
        pengali = mul(pengali,PRIME);   
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s,t;
    cin >> s >> t;
    ll n = s.length();
    ll m = t.length();
    calcHash(s,n,0);
    calcHash(t,m,1);
    vector<ll> ans;
    for (ll i = 0 ; i < n ; i++)
    {
        ll kiriS,kananS,kiriT,kananT;
        if (i == 0)
        {
            kananS = hashBelakang[0][i + 1];
            kananT = hashBelakang[1][i];
            if (kananS == kananT)
                ans.push_back(i);
        }
        else
        if (i == n - 1)
        {
            kiriS = hashDepan[0][i - 1];
            kiriT = hashDepan[1][i - 1];
            if (kiriS == kiriT)
                ans.push_back(i);
        }
        else
        {
            kiriS = hashDepan[0][i - 1];
            kiriT = hashDepan[1][i - 1];
            kananS = hashBelakang[0][i + 1];
            kananT = hashBelakang[1][i];
            if (kiriS == kiriT && kananT == kananS)
                ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it + 1 << " ";
    cout << endl;
    return 0;
}