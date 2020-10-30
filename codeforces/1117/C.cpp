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
#define L 0
#define R 1
#define U 2
#define D 3

int pref[4][100010];
int n;

bool can(int k,int needHor,int needVer)
{
    int rep = k / n;
    int l = (pref[L][n] * rep) + (pref[L][k % n]);
    int r = (pref[R][n] * rep) + (pref[R][k % n]);
    int u = (pref[U][n] * rep) + (pref[U][k % n]);
    int d = (pref[D][n] * rep) + (pref[D][k % n]);
    int curHor = r - l;
    int curVer = u - d;
    int hor = abs(needHor - curHor);
    int ver = abs(needVer - curVer);
    return (hor + ver <= k);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x1,y1;
    cin >> x1 >> y1;
    int x2,y2;
    cin >> x2 >> y2;
    int needHor = x2 - x1;
    int needVer = y2 - y1;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        char ta;
        cin >> ta;
        for (int j = 0 ; j < 4 ; j++)
            pref[j][i] = pref[j][i - 1];
        if (ta == 'L')
            pref[L][i]++;
        if (ta == 'R')
            pref[R][i]++;
        if (ta == 'U')
            pref[U][i]++;
        if (ta == 'D')
            pref[D][i]++;
    }
    int l = 1;
    int r = INFF;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (can(mid,needHor,needVer))
            r = mid;
        else
            l = mid;
    }
    if (can(l,needHor,needVer))
        cout << l << endl;
    else
    if (can(r,needHor,needVer))
        cout << r << endl;
    else
        cout << "-1\n";
    return 0;
}