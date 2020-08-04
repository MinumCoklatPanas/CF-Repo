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

ll cei(ll x,ll y)
{
    return ((x / y) + (x % y != 0));
}

void cek(vector< pair<ll,ll> > &tab,ll x1,ll x2,ll ix)
{
    ll n = tab.size();
    ll need1 = cei(x1,tab[ix].first);
    if (need1 >= n - ix) return;
    ll need2 = cei(x2,tab[need1 + ix].first);
    if (need1 + need2 + ix <= n)
    {
        // cout << ix << " " << x1 << " " << x2 << endl;
        cout << "Yes\n";
        cout << need1 << " " << need2 << endl;
        for (ll i = ix ; i < need1 + ix ; i++)
            cout << tab[i].second + 1 << " ";
        cout << endl;
        for (ll i = need1 + ix ; i < need1 + need2 + ix ; i++)
            cout << tab[i].second + 1 << " ";
        cout << endl;
        exit(0);
    }
}

void cek2(vector< pair<ll,ll> > &tab,ll x1,ll x2,ll ix)
{
    ll n = tab.size();
    ll need1 = cei(x1,tab[ix].first);
    if (need1 >= n - ix) return;
    ll need2 = cei(x2,tab[need1 + ix].first);
    if (need1 + need2 + ix <= n)
    {
        // cout << ix << " " << x1 << " " << x2 << endl;
        cout << "Yes\n";
        cout << need2 << " " << need1 << endl;
        for (ll i = need1 + ix ; i < need1 + need2 + ix ; i++)
            cout << tab[i].second + 1 << " ";
        cout << endl;
        for (ll i = ix ; i < need1 + ix ; i++)
            cout << tab[i].second + 1 << " ";
        cout << endl;
        exit(0);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,x1,x2;
    cin >> n >> x1 >> x2;
    vector< pair<ll,ll> > tab(n);
    for (ll i = 0 ; i < n ; i++)
    {
        cin >> tab[i].first;
        tab[i].second = i;
    }
    sort(tab.begin(),tab.end());
    for (ll i = 0 ; i < n ; i++)
    {
        cek(tab,x1,x2,i);       
        cek2(tab,x2,x1,i);
    }
    cout << "No\n";
    return 0;
}