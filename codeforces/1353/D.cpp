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

struct cmp
{
    bool operator()(pair<int,int> a,pair<int,int> b)
    {
        int lenA = a.second - a.first + 1;
        int lenB = b.second - b.first + 1;
        if (lenA == lenB) return a.first > b.first;
        else return lenA < lenB;
    }
};


void solve()
{
    int n;
    cin >> n;
    vector<int> ans(n + 5,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    pq.push(make_pair(1,n));
    for (int i = 1 ; i <= n ; i++)
    {
        auto cur = pq.top();
        pq.pop();
        int mid = (cur.first + cur.second) / 2;
        ans[mid] = i;
        if (cur.first < mid)
            pq.push({cur.first,mid - 1});
        if (cur.second > mid)
            pq.push({mid + 1,cur.second});
    }
    for (int i = 1 ; i <= n ; i++) cout << ans[i] << " ";
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