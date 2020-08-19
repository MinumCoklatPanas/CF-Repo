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

ll tab[100010];
pair<ll,ll> ans[100010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,q;
    cin >> n >> q;
    deque<ll> dq(n);
    ll mx = 0;
    for (ll i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
        dq[i - 1] = tab[i];
        mx = max(mx,tab[i]);
    }
    ll ix = 1;
    while (dq.front() != mx)
    {
        ll tmp1 = dq.front();
        dq.pop_front();
        ll tmp2 = dq.front();
        dq.pop_front();
        ans[ix++] = {tmp1,tmp2};
        if (tmp1 > tmp2)
        {
            dq.push_front(tmp1);
            dq.push_back(tmp2);
        }
        else
        {
            dq.push_front(tmp2);
            dq.push_back(tmp1);
        }
    }
    // for (auto it : dq)
    //     cout << it << " ";
    // cout << endl;
    while (q--)
    {
        ll k;
        cin >> k;
        if (k < ix)
        {
            // cout << "yo\n";
            cout << ans[k].first << " " << ans[k].second << endl;
        }
        else
        {
            k -= ix;
            k %= dq.size() - 1;
            k++;
            cout << dq.front() << " " << dq[k] << endl;
        }
    }
    return 0;
}