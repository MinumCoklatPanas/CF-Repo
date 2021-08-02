#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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

int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}


int getTC()
{
    if (MULTI_TC)
    {
        int t = readInt();
        return t;
    }
    else return 1;
}

int tab[200010];
int diff[200010];
int t[400010];
int N;

void build() {  // build the tree
  for (int i = N - 1; i > 0; --i) t[i] = __gcd(t[i<<1],t[i<<1|1]);
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = __gcd(res,t[l++]);
    if (r&1) res = __gcd(res,t[--r]);
  }
  return res;
}

void solve()
{
    int n = readInt();
    for (int i = 1 ; i <= n ; i++)
    {
        tab[i] = readInt();
    }
    N = n - 1;
    for (int i = 1 ; i + 1 <= n ; i++)
    {
        t[N + (i - 1)] = abs(tab[i] - tab[i + 1]);
        diff[i] = abs(tab[i] - tab[i + 1]);
    }
    if (n == 1)
    {
        puts("1");
        return;
    }
    build();
    // cerr << query(1,2) << endl;
    // build(1,1,n - 1);
    int ans = 0;
    for (int i = 1 ; i < n ; i++)
    {
        const auto good = [&](int l,int r) -> bool
        {
            int ret = query(l - 1,r);
            return (ret != 1);
        };
        // cerr << good(1,2) << endl;
        // return;
        int lo = i;
        int hi = n - 1;
        while (hi - lo > 1)
        {
            int mid = (lo + hi) >> 1;
            if (good(i,mid))
                lo = mid;
            else
                hi = mid - 1;
        }   
        int len = 0;
        if (good(i,hi))
            len = hi - i + 1;
        else
        if (good(i,lo))
            len = lo - i + 1;
        ans = max(ans,len);
    }
    // int curL = 1;
    // while (curL < n)
    // {
    //     int curGcd = diff[curL];
    //     // cerr << curL << " " << curGcd << endl;
    //     if (curGcd == 1)
    //     {
    //         ++curL;
    //         continue;
    //     }
    //     int r = curL;
    //     while (r < n && curGcd != 1)
    //     {
    //         ++r; 
    //         curGcd = __gcd(curGcd,diff[r]);
    //         // cerr << r << " " << curGcd << endl;
    //     }
    //     cerr << curL << " " << r << endl;
    //     // return; << 
    //     ans = max(ans,r - curL);
    //     curL = r;
    // }
    printf("%lld\n",ans + 1);
    // cout << ans + 1 << endl;
}

signed main()
{
    int t = getTC();
    while (t--)
    {
        solve();
    }
    return 0;
}