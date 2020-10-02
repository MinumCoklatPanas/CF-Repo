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

pair<int,int> tab[200010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector< pair<int,int> > tv[2];
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
        cin >> tab[i].first >> tab[i].second;
    sort(tab + 1,tab + n + 1);
    int cur = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        if (tv[0].empty())
            tv[0].push_back(tab[i]);
        else
        if (tv[1].empty())
            tv[1].push_back(tab[i]);
        else
        {
            if (tab[i].first <= tv[cur].back().second)
            {
                // cout << tab[i].first << " " << tab[i].second << " " << cur << " " << tv[cur ^ 1].back().second << endl;
                if (tab[i].first <= tv[cur ^ 1].back().second)
                {
                    cout << "NO\n";
                    return 0;
                }
                else
                    tv[cur ^ 1].push_back(tab[i]);
            }
            else
                tv[cur].push_back(tab[i]),cur ^= 1;
        }
    }
    cout << "YES\n";
    return 0;
}