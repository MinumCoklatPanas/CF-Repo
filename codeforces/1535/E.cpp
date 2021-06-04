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
        scanf("%lld",&t);
        return t;
    }
    else return 1;
}

int depth[300010];
int spa[20][300010];
int a[300010];
int c[300010];
bool nyala[300010];

void solve()
{
    int q,a0,c0;
    scanf("%lld%lld%lld",&q,&a[0],&c[0]);
    nyala[0] = 1;
    depth[0] = 1;

    const auto ins = [&](int x,int par) -> void
    {
        depth[x] = depth[par] + 1;
        spa[0][x] = par;
        for (int i = 1 ; (1 << i) < depth[x] ; i++)
            spa[i][x] = spa[i - 1][spa[i - 1][x]];
    };

    const auto walk = [&](int x,int k) -> int
    {
        for (int i = 0 ; (1 << i) <= k ; i++) if ((1 << i) & k)
            x = spa[i][x];
        return x;
    };

    for (int i = 1 ; i <= q ; i++)
    {
        int ask;
        scanf("%lld",&ask);
        if (ask == 1)
        {
            int par;
            scanf("%lld%lld%lld",&par,&a[i],&c[i]);
            nyala[i] = 1;
            ins(i,par);
        }
        else
        {
            int x,w;
            scanf("%lld %lld",&x,&w);
            if (!nyala[x])
            {
                printf("0 0\n");
                fflush(stdout);
                continue;
            }
            int l = 0;
            int r = depth[x] - 1;
            // cerr << i << " " << l << " " << r << endl;
            int ambil = -1;
            while (r - l > 1)
            {
                int mid = (l + r) / 2;
                int tmp = walk(x,mid);
                if (nyala[tmp])
                    l = mid;
                else
                    r = mid - 1;
            }
            int tmpR = walk(x,r);
            int curDepth;
            if (nyala[tmpR])
            {
                ambil = tmpR;
                curDepth = r;
            }
            else
            {
                int tmpL = walk(x,l);
                if (nyala[tmpL])
                {
                    ambil = tmpL;
                    curDepth = l;
                }
            }
            // cerr << i << " " << ambil << endl;
            assert(ambil != -1);
            int ansTake = 0;
            int ansCost = 0;
            while (w > 0 && curDepth >= 0)
            {
                int kurang = min(a[ambil],w);
                a[ambil] -= kurang;
                w -= kurang;
                if (a[ambil] == 0) nyala[ambil] = 0;
                ansTake += kurang;
                ansCost += kurang * c[ambil];
                --curDepth;
                if (curDepth >= 0)
                    ambil = walk(x,curDepth);   
            }
            printf("%lld %lld\n",ansTake,ansCost);
            fflush(stdout);
            // cout << ansTake << " " << ansCost << endl;
        }
    }
}

signed main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t = getTC();
    while (t--)
    {
        solve();
    }
    return 0;
}