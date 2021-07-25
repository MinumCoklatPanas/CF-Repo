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
    int hehe;
    int n,k;
    cin >> n >> k;
    vector< pair<int,int> > tab(n);
    for (auto &it : tab) 
    {
        it.first = 1;
        cin >> it.second;
    }
    if (n == 1)
    {
        cout << tab[0].second - 1 << endl;
        return;
    }
    vector< pair<int,int> > suf(n);
    suf[n - 1].first = 1;
    suf[n - 1].second = tab[n - 1].second;
    for (int i = n - 2 ; i >= 0 ; i--)
    {
        suf[i].first = suf[i + 1].first + 1;
        suf[i].second = suf[i + 1].second + tab[i].second;
    }
    int curL = 1;
    int curR = tab[0].second;
    int needL = k - curR;
    int needR = k - curL;
    // cerr << needL << " " << needR << endl;
    int nextL = suf[1].first;
    int nextR = suf[1].second;
    int intersectL = max(needL,nextL);
    int intersectR = min(needR,nextR);
    int len = intersectR - intersectL + 1;
    int notUsed = tab[0].second - len;
    cout << notUsed << " ";
    curL = k - intersectR;
    curR = k - intersectL;
    for (int i = 1 ; i < n ; i++)
    {
        needL = k - curR;
        needR = k - curL;
        nextL = max(1ll,needL - (i + 1 < n ? suf[i + 1].second : 0));
        nextR = max(1ll,needR - (i + 1 < n ? suf[i + 1].first : 0));
        intersectL = max(nextL,1ll);
        intersectR = min(nextR,tab[i].second);
        // cerr << intersectL << " " << intersectR << endl;
        len = intersectR - intersectL + 1;
        notUsed = tab[i].second - len;
        cout << notUsed << " ";
        curL += intersectL;
        curR += intersectR;
        curL = min(curL,k);
        curR = min(curR,k);
    }
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