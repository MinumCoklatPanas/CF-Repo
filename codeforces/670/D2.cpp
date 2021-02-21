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

bool ok(int num,int k,vector<int> &a, vector<int> &b) 
{
    int need = 0;
    for (int i = 0 ; i < a.size() ; i++)
    {
        need += max(0ll,a[i] * num - b[i]);
        if (need > k) return 0;
    }
    // cout << need << endl;
    return (need <= k);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> a(n),b(n);
    for (auto &it : a) cin >> it;
    for (auto &it : b) cin >> it;
    int l = 0;
    int r = 2e9;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        // cout << mid << " ";
        if (ok(mid,k,a,b))
            l = mid;
        else
            r = mid - 1;
    }
    if (ok(r,k,a,b))
        cout << r << endl;
    else
        cout << l << endl;
    return 0;
}