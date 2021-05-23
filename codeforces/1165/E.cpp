#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 998244353;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define MULTI_TC 0

int getTC()
{
    if (MULTI_TC)
    {
        int t;
        cin >> t;
        return t;
    }
    else return 1;
}

int add(int x,int y)
{
    return ((x % MOD) + (y % MOD)) % MOD;
}

int mul(int x,int y)
{
    return ((x % MOD) * (y % MOD)) % MOD;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (auto &it : a) cin >> it;
    for (auto &it : b) cin >> it;
    sort(b.begin(),b.end());
    priority_queue<int> pq;
    for (int i = 1 ; i <= n ; i++)
    {
        int contrib =  i * (n - i + 1) * a[i - 1];
        pq.push(contrib);
    }
    int ans = 0;
    for (int i = 0 ; i < n ; i++)
    {
        ans = add(ans,mul(b[i],pq.top()));
        pq.pop();
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = getTC();
    while (t--)
    {
        solve();
    }
    return 0;
}