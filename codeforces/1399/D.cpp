#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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

string s;
int ans[200010];
string res[200010];
set<int> q[2];

void mark(int a,int k)
{
    ans[*(q[a].begin())] = k;
    int cur = *(q[a].begin());
    q[a].erase(q[a].begin());
    while (1)
    {
        auto nxt = q[a ^ 1].lower_bound(cur);
        if (nxt == q[a ^ 1].end()) break;
        int tmp = *nxt;
        q[a ^ 1].erase(nxt);
        a ^= 1;
        ans[tmp] = k;
        cur = tmp;
    }
}

void solve()
{
    int n;
    cin >> n;
    cin >> s;
    q[0].clear();
    q[1].clear();
    for (int i = 0 ; i < n ; i++)
    {
        if (s[i] == '0')
            q[0].insert(i);
        else
            q[1].insert(i);
    }
    int cnt = 1;
    while (!q[0].empty() && !q[1].empty())
    {
        int a = *q[0].begin();
        int b = *q[1].begin();
        // cout << a << " " << b << endl;
        // return;
        if (a < b)
        {
            mark(0,cnt);
            // return;
        }
        else
            mark(1,cnt);
        ++cnt;
    }
    for (auto it : q[0])
        ans[it] = cnt++;
    for (auto it : q[1])
        ans[it] = cnt++;
    cout << cnt - 1 << endl;
    for (int i = 0 ; i < n ; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}