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

vector<int> tab[55];
int n,x;

int rec(int ix,int prod)
{
    if (prod > x) return 0;
    if (ix > n) return (prod == x);
    int ret = 0;
    for (auto it : tab[ix])
    {
        ret += rec(ix + 1,prod * it);
    }
    return ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    vector<int> num,place;
    for (int i = 1 ; i <= n ; i++)
    {
        int k;
        cin >> k;
        for (int j = 1 ; j <= k ; j++)
        {
            int ta;
            cin >> ta;
            tab[i].push_back(ta);
        }
    }
    int ans = rec(1,1);
    cout << ans << endl;
    return 0;
}