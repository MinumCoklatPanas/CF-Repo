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

int add(int x,int y)
{
    return ((x % MOD) + (y % MOD)) % MOD;
}

int dp1[1010]; //num of partitions
int dp2[1010]; //max len
int dp3[1010]; //min partition
int n;
int pref[35][1010];
int tab[35];
char s[1010];

int get(int k,int l,int r)
{
    return pref[k][r] - pref[k][l - 1];
}

int rec1(int ix)
{
    if (ix > n) return 1;
    if (dp1[ix] != -1) return dp1[ix];
    int ret = 0;
    int mask = 0;
    for (int i = ix ; i <= n ; i++)
    {
        bool valid = 1;
        int tmp = s[i] - 'a';
        mask |= (1 << tmp);
        for (int j = 0 ; j < 26 ; j++) if (mask & (1 << j))
        {
            int cnt = i - ix + 1;
            if (cnt > tab[j])
            {
                valid = 0;
                break;
            }
        }
        if (valid)
            ret = add(ret,rec1(i + 1));
    }
    return dp1[ix] = ret;
}

int rec2(int ix)
{
    if (ix > n) return -INF;
    if (dp2[ix] != -1) return dp2[ix];
    int ret = 0;
    int mask = 0;
    for (int i = ix ; i <= n ; i++)
    {
        bool valid = 1;
        int tmp = s[i] - 'a';
        mask |= (1 << tmp);
        for (int j = 0 ; j < 26 ; j++) if (mask & (1 << j))
        {
            int cnt = i - ix + 1;
            if (cnt > tab[j])
            {
                valid = 0;
                break;
            }
        }
        if (valid)
            ret = max(ret,max(i - ix + 1,rec2(i + 1)));
    }
    return dp2[ix] = ret;
}

int rec3(int ix)
{
    if (ix > n) return 0;
    if (dp3[ix] != -1) return dp3[ix];
    int ret = INF;
    int mask = 0;
    for (int i = ix ; i <= n ; i++)
    {
        bool valid = 1;
        int tmp = s[i] - 'a';
        mask |= (1 << tmp);
        for (int j = 0 ; j < 26 ; j++) if (mask & (1 << j))
        {
            int cnt = i - ix + 1;
            if (cnt > tab[j])
            {
                valid = 0;
                break;
            }
        }
        if (valid)
            ret = min(ret,1 + rec3(i + 1));
    }
    // cout << ix << " " << ret << endl;
    return dp3[ix] = ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
        cin >> s[i];
    for (int i = 0 ; i < 26 ; i++)
        cin >> tab[i];
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    memset(dp3,-1,sizeof(dp3));
    int ans1 = rec1(1);
    int ans2 = rec2(1);
    int ans3 = rec3(1);
    cout << ans1 << endl;
    cout << ans2 << endl;
    cout << ans3 << endl;
    return 0;
}