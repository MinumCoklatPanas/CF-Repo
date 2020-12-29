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

int dp[55][2];
int tab[55];
int n;

int rec(int index,int decider)
{
    if (index > n) return 0;
    if (dp[index][decider] != -1) return dp[index][decider];
    int ret;
    if (decider == 0)
    {
        ret = max(tab[index] + rec(index + 1,1),rec(index + 1,0));
    }
    else
    {
        ret = min(tab[index] + rec(index + 1,1),rec(index + 1,0));
    }
    // cout << index << " " << decider << " " << ret << endl;
    return dp[index][decider] = ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int sum = 0;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> tab[i],sum += tab[i];
    memset(dp,-1,sizeof(dp));
    int bob = rec(1,0);
    int alice = sum - bob;
    cout << alice << " " << bob << endl;
    return 0;
}