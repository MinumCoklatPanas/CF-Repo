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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    vector< pair<char,ll> > vp;
    for (ll i = 0 ; i < s.length() ; i++)
    {
        if (vp.size() == 0)
        {
            vp.push_back({s[i],(s[i] == 'o')});
        }
        else
        if (vp.back().first == s[i])
            ++vp.back().second;
        else
            vp.push_back({s[i],(s[i] == 'o')}); 
    }
    ll ans = 0;
    ll w = 0;
    for (auto it : vp) if (it.first == 'v')
        w += it.second;
    ll done = 0;
    for (auto it : vp)
    {
        if (it.first == 'v')
        {
            done += it.second;
            w -= it.second;
        }
        else
        {
            ans += it.second * (done * w);
        }
    }
    cout << ans << endl;
    return 0;
}