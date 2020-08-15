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

int a[100010];
int b[100010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    for (int j = 1 ; j <= m ; j++) cin >> b[j];
    int ptr = 1;
    vector< pair<int,int> > ans;
    for (int i = 1 ; i <= n ; i++)
    {
        int l = a[i] - x;
        int r = a[i] + y;
        for ( ; ptr <= m ; ptr++)
        {
            if (b[ptr] > r) break;
            if (l <= b[ptr] && b[ptr] <= r)
            {
                ans.emplace_back(i,ptr);
                ++ptr;
                break;
            }
        } 
    }
    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it.first << " " << it.second << endl;
    return 0;
}