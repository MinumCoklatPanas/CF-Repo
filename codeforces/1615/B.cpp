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
#define MULTI_TC 1

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
    int l,r;
    cin >> l >>r;
    int nearest2 = 1;
    while (nearest2 <= l) nearest2 *= 2;
    nearest2 /= 2;
    const auto f = [&](int x,int k) -> int
    {
        if (x == 0) return 0;
        int dua = (1 << k);
        int rem = x / dua;
        if (rem % 2 == 0)
            return max(0ll,dua * (rem / 2));
        else
        {
            int nambah = x % dua;
            ++nambah;
            --rem;
            rem /= 2;
            int ret = rem * dua + nambah;
            return ret;
        }
    };
    const auto cnt = [&](int a,int b,int k)
    {
        return f(b,k) - f(a - 1,k);
    };
    int ans = INF;
    for (int i = 0 ; i < 20 ; i++)
    {
        int inside = cnt(l,r,i);
        int hapus = (r - l + 1) - inside;
        ans = min(ans,hapus);
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