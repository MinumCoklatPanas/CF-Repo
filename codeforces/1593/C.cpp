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
    int n,k;
    cin >> n >> k;
    vector<int> tab(k);
    for (auto &it : tab) cin >> it;
    tab.push_back(0);
    sort(tab.begin(),tab.end());
    reverse(tab.begin(),tab.end());
    int micePos = 0;
    int catPos = k;
    int realPos = 0;
    int ans = 0;
    while (micePos < catPos)
    {
        int need = n - tab[micePos];
        int nextJump = realPos + need;
        while (tab[catPos] <= nextJump) --catPos;
        if (tab[catPos] > nextJump)
            ++catPos;
        realPos = nextJump;
        // cerr << need << " " << nextJump << " " << catPos << " " << realPos << endl;
        ++ans;
        ++micePos;
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