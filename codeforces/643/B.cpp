#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
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

void solve()
{
    int n,k;
    cin >> n >> k;
    if (n == 4 || (k < n + 1))
    {
        cout << -1 << endl;
        return;
    }
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    vector<int> ans1;
    ans1.push_back(a);
    ans1.push_back(c);
    for (int i = 1 ; i <= n ; i++) if (i != a && i != b && i != c)
        ans1.push_back(i);
    ans1.push_back(b);
    int posc,posd;
    for (int i = 0 ; i < n ; i++)
    {
        if (ans1[i] == c) posc = i;
        if (ans1[i] == d) posd = i;
    }
    swap(ans1[3],ans1[posd]);
    vector<int> ans2;
    ans2.push_back(c);
    ans2.push_back(a);
    ans2.push_back(ans1[2]);
    for (int i = n - 1 ; i >= 3 ; i--)
        ans2.push_back(ans1[i]);
    for (auto it : ans1)
        cout << it << " ";
    cout << endl;
    for (auto it : ans2)
        cout << it << " ";
    cout << endl;
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