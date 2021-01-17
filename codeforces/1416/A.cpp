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

vector<int> pos[300010];
int ans[300010];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) pos[i].clear(),ans[i] = -1,pos[i].push_back(0);
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        pos[ta].push_back(i);
    }
    for (int i = 1 ; i <= n ; i++) pos[i].push_back(n + 1);
    int leftMost = n;
    for (int i = 1 ; i <= n ; i++)
    {
        int mx = 0;
        for (int j = 1 ; j < pos[i].size() ; j++)
        {
            mx = max(mx,pos[i][j] - pos[i][j - 1]);
        }
        if (mx)
        {
            for (int j = mx ; j <= leftMost ; j++) ans[j] = i;
            if (mx <= leftMost)
                leftMost = mx - 1;
        }
        // cout << i << " " << leftMost << endl;
    }
    for (int i = 1 ; i <= n ; i++)
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