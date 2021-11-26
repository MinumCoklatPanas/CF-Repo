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

int add(int x,int y)
{
    return ((x % MOD) + (y % MOD)) % MOD;
}

int sub(int x,int y)
{
    int ret = ((x % MOD) - (y % MOD)) % MOD;
    if (ret < 0) ret += MOD;
    return ret;
}

int mul(int x,int y)
{
    return ((x % MOD) * (y % MOD)) % MOD;
}

int modpow(int x,int y)
{
    if (!y) return 1;
    int z = modpow(x,y / 2);
    z = mul(z,z);
    if (y & 1) z = mul(z,x);
    return z;
}

int reverse(int x)
{
    return modpow(x,MOD - 2);
}

int bagi (int x,int y)
{
    return mul(x,reverse(y));
}


int fak[200010];

int comb(int x,int y)
{
    int atas = fak[x];
    int bawah = mul(fak[y],fak[x - y]);
    return bagi(atas,bawah);
}

int pangkat[200010];

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<pair<pair<int,int>,int>> tab(m);
    for (auto &it : tab)
        cin >> it.first.first >> it.first.second >> it.second;
    sort(tab.begin(),tab.end());
    int curL = -1,curR = -1,curSum = 0;
    vector<pair<pair<int,int>,int>> merged;
    for (auto it : tab)
    {
        if (it.first.first > curR)
        {
            // cerr << "yo\n";
            if (curL != -1)
            {
                merged.push_back({{curL,curR},curSum});
            }
            curL = it.first.first;
            curR = it.first.second;
            curSum = it.second;
        }
        else
        {
            curR = max(curR,it.first.second);
            curSum |= it.second;
        }
    }
    merged.push_back({{curL,curR},curSum});
    vector<int> cnt(30,0);
    for (auto it : merged)
    {
        int cur = it.second;
        // cerr << cur << endl;
        for (int i = 0 ; i < 30 ; i++) if (cur & (1 << i))
            ++cnt[i];
    }
    int ans = 0;
    for (int i = 0 ; i < 30 ; i++)
    {
        int pan = pangkat[i];
        for (int j = 1 ; j <= cnt[i] ; j += 2)
        {
            int choose = comb(cnt[i],j);
            // int a = pan[1];
            int ot = pangkat[n - cnt[i]];
            // int other = modpow(2,n - cnt[i]);
            int res = mul(choose,ot);
            int sisa = cnt[i] - j;
            // if (sisa > 1)
            // {
            //     int hehe = pangkat[sisa - 1] - 1;
            //     res = mul(res,hehe);
            //     // res = mul(res,modpow(2,sisa - 2));
            // }
            // cerr << i << " " << j << " " << res << endl;
            ans = add(ans,mul(pan,res));
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fak[0] = 1;
    pangkat[0] = 1;
    for (int i = 1 ; i <= 200000 ; i++)
    {
        fak[i] = mul(fak[i - 1],i);
        pangkat[i] = mul(pangkat[i - 1],2);
    }
    int t = getTC();
    while (t--)
    {
        solve();
    }
    return 0;
}