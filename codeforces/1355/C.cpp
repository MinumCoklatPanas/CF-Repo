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
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int ans = 0;

    const auto cnt = [&](int l,int r) -> int
    {
        return ((l + r) * (r - l + 1)) / 2;
    };
    for (int i = c ; i <= d ; i++)
    {
        if (b + c <= i) break;
        int startPoint = max(i - c + 1,a);
        int startNeed = c - i + startPoint;
        // cerr << i << " " << startPoint << " " << startNeed << endl;
        int totalLength = c - b + 1;
        int cntNotFull = max(0ll,totalLength - startNeed);
        int cntAll = b - startPoint + 1;
        // cerr << cntNotFull << " " << cntAll << endl;
        if (cntNotFull > cntAll)
        {
            ans += cnt(startNeed,startNeed + cntAll - 1);
        }
        else
        {
            ans += cnt(startNeed,startNeed + cntNotFull - 1);
            // cerr << ans << " ans\n";
            ans += (cntAll - cntNotFull) * totalLength;
        }
        // cerr << "-------------------------\n";
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