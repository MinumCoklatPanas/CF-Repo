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
#define int long long

int tab[7010];
int val[7010];
map< int,vector<int> > mp;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> tab[i],mp[tab[i]].push_back(i);
    for (int i = 1 ; i <= n ; i++) cin >> val[i];
    int ans = 0;
    vector<int> v;
    for (auto it : mp)
    {
        if (it.second.size() > 1)
        {
            for (auto it2 : it.second)
                ans += val[it2];  
            v.push_back(it.first);
        }
    }
    for (auto it : mp)
    {
        if (it.second.size() == 1)
        {
            for (auto it2 : v)
            {
                if ((it.first & it2) == it.first)
                {
                    ans += val[it.second[0]];
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}