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
    ll n,k;
    cin >> n >> k;
    deque<ll> onlyA,onlyB,both;
    for (ll i = 1 ; i <= n ; i++)
    {
        ll val,a,b;
        cin >> val >> a >> b;
        if (a && b)
            both.push_back(val);
        else
        if (a)
            onlyA.push_back(val);
        else
        if (b)
            onlyB.push_back(val);
    }
    sort(onlyA.begin(),onlyA.end());
    sort(onlyB.begin(),onlyB.end());
    sort(both.begin(),both.end());
    ll takeA = onlyA.size();
    ll takeB = onlyB.size();
    ll harus = 0;
    ll ans = 0;
    while (takeA < k && !both.empty())
    {
        ll cur = both.front();
        both.pop_front();
        ++takeA;
        ++takeB;
        ++harus;
        ans += cur;
        // cout << cur << endl;
    }
    while (takeB < k && !both.empty())
    {
        // cout << "yo\n";
        ll cur = both.front();
        both.pop_front();
        ++takeA;
        ++takeB;
        ++harus;
        ans += cur;
    }
    if (takeA < k || takeB < k)
        cout << -1 << endl;
    else
    {
        while (onlyA.size() > max(0ll,k - harus))
            onlyA.pop_back();
        while (onlyB.size() > max(0ll,k - harus))
            onlyB.pop_back();
        for (auto it : onlyA)
        {
            // cout << it << " ";
            ans += it;
        }
        // cout << endl;
        for (auto it : onlyB)
        {
            // cout << it << " ";
            ans += it;
        }
        // cout << endl;
        for (auto it : both)
        {
            if (onlyA.empty() || onlyB.empty()) break;
            if (onlyA.back() + onlyB.back() > it)
            {
                ans += it - (onlyA.back() + onlyB.back());
                onlyA.pop_back();
                onlyB.pop_back();
            }
        }
        cout << ans << endl;
    }
    return 0;
}