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

pair<int,int> tab[100010];
int pref[100010];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n >> m;
        for (int i = 1 ; i <= m ; i++)
        {
            cin >> tab[i].first >> tab[i].second;
        }
        int ans = 0;
        sort(tab + 1,tab + m + 1);
        reverse(tab + 1,tab + m + 1);
        if (n <= m)
        {
            for (int i = 1 ; i <= n ; i++)
                ans += tab[i].first;
        }
        for (int i = 1 ; i <= m ; i++) pref[i] = pref[i - 1] + tab[i].first;
        tab[0].first = INFF;
        for (int i = 1 ; i <= m ; i++)
        {
            int l = 0;
            int r = m;
            while (r - l > 1)
            {
                int mid = (l + r) >> 1;
                if (tab[mid].first > tab[i].second)
                    l = mid;
                else
                    r = mid - 1;
            }
            int bound;
            if (tab[r].first > tab[i].second)
                bound = r; 
            else
                bound = l;
            int tmp;
            bound = min(bound,n - 1);
            if (bound < i)
            {
                tmp = pref[bound] + tab[i].first + (n - (bound + 1)) * tab[i].second;
            }
            else
            {
                tmp = pref[bound] + (n - bound) * tab[i].second;
            }
            // cout << i << " " << bound << " " << tmp << endl;
            ans = max(ans,tmp);
        }   
        cout << ans << endl;
    }
    return 0;
}