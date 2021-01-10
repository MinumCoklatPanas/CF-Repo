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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector< pair< pair<int,int>,int > > line;
    int n,k;
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        line.push_back({{a,1},c});
        line.push_back({{b + 1,0},c});
    }
    sort(line.begin(),line.end());
    int curSum = line[0].second;
    int ans = 0;
    for (int i = 1 ; i < line.size() ; i++)
    {
        // cout << "----------------------------\n";
        // cout << (line[i].first.first - line[i - 1].first.first) << " " << curSum << endl;
        ans += (line[i].first.first - line[i - 1].first.first) * min(curSum,k);
        if (line[i].first.second == 0)
        {
            curSum -= line[i].second;
        }
        else
        {
            curSum += line[i].second;
            // cout << curSum << endl;
            // curSum = min(curSum,k);
        }
        // cout << "----------------------------\n";
    }
    cout << ans << endl;
    return 0;
}