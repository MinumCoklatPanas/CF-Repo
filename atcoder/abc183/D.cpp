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
#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,w;
    cin >> n >> w;
    vector< pair<pair<int,int>,int> > line;
    for (int i = 1 ; i <= n ; i++)
    {
        int l,r,k;
        cin >> l >> r >> k;
        line.push_back({{l,1},k});
        line.push_back({{r,0},k});
    }
    sort(line.begin(), line.end());
    int sum = 0;
    for (auto it : line)
    {
        if (it.first.second == 1)
            sum += it.second;
        else
            sum -= it.second;
        if (sum > w)
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}