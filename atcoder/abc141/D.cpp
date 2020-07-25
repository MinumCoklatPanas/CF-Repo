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
    ll n,m;
    cin >> n >> m;
    priority_queue< ll > pq;
    for (ll i = 1 ; i <= n ; i++)
    {
        ll ta;
        cin >> ta;
        pq.push(ta);
    }
    for (ll i = 1 ; i <= m ; i++)
    {
        ll cur = pq.top();
        pq.pop();
        pq.push(cur / 2);
    }
    ll ans = 0;
    for (ll i = 1 ; i <= n ; i++)
    {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
    return 0;
}