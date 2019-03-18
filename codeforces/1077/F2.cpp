#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MOD = 1e9 + 7;
const ll MAXN = 210;

ll readInt ()
{
    bool minus = false;
    ll result = 0;
    char ch;
    ch = getchar();
    while (true)
    {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true;
    else result = ch-'0';
    while (true)
    {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}


inline void writeInt (ll n)
{
    ll NN = n, rev, count = 0;
    rev = NN;
    if (NN == 0) { putchar('0');  return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (NN != 0) { rev = (rev<<3) + (rev<<1) + NN % 10; NN /= 10;}  //store reverse of N in rev
    while (rev != 0) { putchar(rev % 10 + '0'); rev /= 10;}
    while (count--) putchar('0');
}

ll DP[5010][5010];
ll tab[5010];

bool InRange(ll x,ll l,ll r)
{
    return (l <= x && x <= r);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll n,k,x;
    cin >> n >> k >> x;
    for (ll i = 1 ; i <= n ; i++)
        cin >> tab[i];
    for (ll i = 1 ; i <= x ; i++)
        for (ll j = 0 ; j <= n ; j++)
            DP[i][j] = -INFF;
    DP[x][0] = 0;
    for (ll i = x - 1 ; i >= 0 ; i--)
    {
        deque< pair<ll,ll> > dq;
        dq.push_back(make_pair(DP[i + 1][0],0ll));
        for (ll j = 1 ; j <= n ; j++)
        {
            // cout << i << " " << j << endl;
            ll L = max(0ll,j - k);
            ll R = j - 1;
            while (!dq.empty() && !InRange(dq.front().second,L,R))
                dq.pop_front();
            ll mx = dq.front().first;
            // cout << mx << " mx\n";
            ll val = (mx == -INFF ? -INFF : mx + tab[j]);
            // cout << val << " val\n";
            while (!dq.empty() && dq.back().first < DP[i + 1][j])
                dq.pop_back();
            dq.push_back(make_pair(DP[i + 1][j],j));
            DP[i][j] = val;
            // cout << DP[i][j] << endl;
        }
    }
    ll ans = -INFF;
    // for (ll i = 0 ; i < x ; i++)
        for (ll j = n - k + 1 ; j <= n ; j++)
            ans = max(ans,DP[0][j]);
    if (ans == -INFF)
        cout << -1 << endl;
    else
        cout << ans << endl;
}