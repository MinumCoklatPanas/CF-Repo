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
    int n,k;
    scanf("%lld %lld",&n,&k);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for (int i = 1 ; i <= n ; i++)
    {
        int l,r;
        scanf("%lld %lld",&l,&r);
        pq.push({l,-1});
        pq.push({r,1});
    }
    int cnt = 0;
    vector<pair<int,int>> ans;
    int curL = -INFF;
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int x = cur.first;
        int status = cur.second;
        if (status == -1)
        {
            ++cnt;
            if (cnt == k)
            {
                curL = x;
            }
        }
        else
        {
            --cnt;
            if (cnt == k - 1 && curL != -INFF)
            {
                ans.push_back({curL,x});
            }
        }
    }
    printf("%lld\n",(ll)ans.size());
    for (auto it : ans)
        printf("%lld %lld\n",it.first,it.second);
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