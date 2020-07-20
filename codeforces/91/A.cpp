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

vector<int> pos[30];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s,t;
    cin >> s >> t;
    for (int i = 0 ; i < s.length() ; i++)
        pos[s[i] - 'a' + 1].push_back(i);
    int curPos = -1;
    int ans = 1;
    for (int i = 0 ; i < t.length() ; i++)
    {
        int ix = t[i] - 'a' + 1; 
        if (pos[ix].empty())
        {
            cout << -1 << endl;
            return 0;
        }
        int nxt = upper_bound(pos[ix].begin(),pos[ix].end(),curPos) - pos[ix].begin();
        if (nxt == pos[ix].size())
        {
            ans++;
            curPos = pos[ix][0];
        }
        else
            curPos = pos[ix][nxt];
    }
    cout << ans << endl;
    return 0;
}