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

map< pair<ll,ll>,ll > mp;

ll msb(ll x)
{
    ll ret = 1;
    while (ret <= x)
        ret *= 2;
    ret /= 2;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll q;
    cin >> q;
    while (q--)
    {
        ll ask,u,v;
        cin >> ask >> u >> v;
        if (ask == 1)
        {
            ll w;
            cin >> w;
            ll lu = msb(u);
            ll lv = msb(v);
            if (lu < lv)
            {
                swap(u,v);
                swap(lu,lv);
            }
            while (lu != lv)
            {
                ll papa = u / 2;
                mp[{u,papa}] += w;
                mp[{papa,u}] += w;
                u /= 2;
                lu /= 2;
            }
            while (u != v)
            {
                ll papa = u / 2;
                mp[{u,papa}] += w;
                mp[{papa,u}] += w;
                u /= 2;
                lu /= 2;

                papa = v / 2;
                mp[{v,papa}] += w;
                mp[{papa,v}] += w;
                v /= 2;
                lv /= 2;
            }
        }
        else
        {
            ll ans = 0;
            ll lu = msb(u);
            ll lv = msb(v);
            if (lu < lv)
            {
                swap(u,v);
                swap(lu,lv);
            }
            while (lu != lv)
            {
                ll papa = u / 2;
                ans += mp[{u,papa}];
                u /= 2;
                lu /= 2;
            }

            while (u != v)
            {
                ll papa = u / 2;
                ans += mp[{u,papa}];
                u /= 2;
                lu /= 2;

                papa = v / 2;
                ans += mp[{v,papa}];
                v /= 2;
                lv /= 2;
            }
            cout << ans << endl;
        }
    }
    return 0;
}