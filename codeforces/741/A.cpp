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

int in[110];
int nxt[110];
bool vis[110];

int lcm(int a,int b)
{
    return (a * b) / __gcd(a,b);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> nxt[i];
        in[nxt[i]]++;
    }
    for (int i = 1 ; i <= n ; i++) if (in[i] != 1)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<int> nums;
    for (int i = 1 ; i <= n ; i++) if (!vis[i])
    {
        int cur = i;
        int cnt = 0;
        do 
        {
            vis[cur] = 1;
            ++cnt;
            cur = nxt[cur];
        } while (cur != i);
        nums.push_back(cnt);
    }
    int ans = 1;
    for (auto it : nums)
    {
        if (it & 1)
            ans = lcm(ans,it);
        else
            ans = lcm(ans,it / 2);
    }
    cout << ans << endl;
    return 0;
}