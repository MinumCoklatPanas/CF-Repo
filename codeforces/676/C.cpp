#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int pref[2][100010];

int get(int kode,int l,int r)
{
    return (pref[kode][r] - pref[kode][l - 1]);
}

int n,k;
int find(int ix,int kode)
{
    int l = 1;
    int r = ix;
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        if (get(kode ^ 1,mid,ix) <= k)
            r = mid;
        else
            l = mid;
    }
    // cout << l << " " << r << endl;
    if (get(kode ^ 1,l,ix) <= k)
        return ix - l + 1;
    else
        return ix - r + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++)
    {
        char ta;
        cin >> ta;
        pref[0][i] = pref[0][i - 1];
        pref[1][i] = pref[1][i - 1];
        if (ta == 'a')
            pref[0][i]++;
        else
            pref[1][i]++;
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        ans = max(ans,find(i,0));
        ans = max(ans,find(i,1));
    }
    cout << ans << endl;
    return 0;
}
