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

ll tab[110];
map<string,ll> cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin >> n >> k;
    for (ll i = 1 ; i <= n ; i++) cin >> tab[i];
    for (ll i = 1 ; i <= k ; i++)
    {
        string ta;
        cin >> ta;
        cnt[ta]++;
    }
    vector<ll> frek;
    for (auto it : cnt)
        frek.push_back(it.second);
    sort(frek.begin(),frek.end());
    sort(tab + 1,tab + n + 1);
    reverse(frek.begin(),frek.end());
    // for (auto it : frek)
    //     cout << it << " " << endl;
    ll mn = 0;
    for (ll i = 0 ; i < frek.size() ; i++)
        mn += frek[i] * tab[i + 1];
    
    // reverse(frek.begin(),frek.end());
    reverse(tab + 1,tab + n + 1);
    ll mx = 0;
    for (ll i = 0 ; i < frek.size() ; i++)
        mx += frek[i] * tab[i + 1];
    cout << mn << " " << mx << endl;
    return 0;
}