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

struct kn
{
    int w,v;
    kn(){}
};
vector<int> nums;
int n,k;
int ans;
map<int,vector<int>> mp;

void rec(int depth,int curW,int curV)
{
    if (depth == nums.size())
    {
        if (curW <= k)
            ans = max(ans,curV);
        return;
    }
    rec(depth + 1,curW,curV);
    for (int i = 1 ; i <= mp[nums[depth]].size() ; i++)
    {
        curW += nums[depth];
        curV += mp[nums[depth]][i - 1];
        rec(depth + 1,curW,curV);
    }
}

void solve()
{
    cin >> n >> k;
    for (int i = 0 ; i < n ; i++)
    {
        int w,v;
        cin >> w >> v;
        mp[w].push_back(v);
    }
    for (auto &it : mp)
    {
        sort(it.second.begin(),it.second.end());
        reverse(it.second.begin(),it.second.end());
        nums.push_back(it.first);
    }
    rec(0,0,0);
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