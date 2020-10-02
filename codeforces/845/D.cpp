#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
typedef short int si;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

struct dat
{
    si type,s;
};

dat tab[200010];
int n;
map< pair<int,pair<int,int>> ,int > dp;
// int dp[200005][305][2]; //[indeks][speedLimit][canOvertake]
si speed[200010];

int rec(int indeks,int speedLimit,int canOvertake)
{
    if (indeks > n) return 0;
    if (dp.count({indeks,{speedLimit,canOvertake}})) return dp[{indeks,{speedLimit,canOvertake}}];
    int ret = INF;
    int curSpeed = speed[indeks];
    if (tab[indeks].type == 1)
    {
        if (curSpeed > speedLimit)
            return INF;
        else
            return dp[{indeks,{speedLimit,canOvertake}}] = rec(indeks + 1,speedLimit,canOvertake);
    }
    if (tab[indeks].type == 2)
    {
        if (!canOvertake)
            return INF;
        else
            return dp[{indeks,{speedLimit,canOvertake}}] = rec(indeks + 1,speedLimit,canOvertake);
    }
    if (tab[indeks].type == 3)
    {
        ret = min(ret,rec(indeks + 1,speedLimit,canOvertake) + 1);
        if (tab[indeks].s >= curSpeed)
            ret = min(ret,rec(indeks + 1,tab[indeks].s,canOvertake));
    }
    if (tab[indeks].type == 4)
    {
        ret = min(ret,rec(indeks + 1,speedLimit,1));
    }
    if (tab[indeks].type == 5)
    {
        ret = min(ret,rec(indeks + 1,301,canOvertake));
    }
    if (tab[indeks].type == 6)
    {
        ret = min(ret,rec(indeks + 1,speedLimit,canOvertake) + 1);
        ret = min(ret,rec(indeks + 1,speedLimit,0));
    }
    return dp[{indeks,{speedLimit,canOvertake}}] = ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        si type,s;
        cin >> type;
        s = -1;
        if (type == 1 || type == 3)
            cin >> s;
        tab[i].type = type;
        tab[i].s = s;
        if (type == 1)
            speed[i] = s;
        else
            speed[i] = speed[i - 1];
    }
    int ans = rec(1,301,1);
    cout << ans << endl;
    return 0;
}