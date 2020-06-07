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

bool ada[15];
int m;
vector<int> ans;

bool dfs(int bal,int prev,int take)
{
    if (abs(bal) > 10) return 0;
    if (take == m + 1)
    {
        return 1;
    }
    int mul = (take % 2 == 0 ? -1 : 1);
    for (int i = 1 ; i <= 10 ; i++) if (ada[i] && i != prev && abs(i * mul) > abs(bal))
    {
        if (dfs(bal + (i * mul),i,take + 1))
        {
            ans.push_back(i);
            return 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1 ; i <= 10 ; i++)
    {
        char ta;
        cin >> ta;
        ada[i] = (ta == '1');
    }
    cin >> m;
    if (dfs(0,0,1))
    {
        cout << "YES\n";
        reverse(ans.begin(),ans.end());
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    else
    {
        cout << "NO\n";
    }
    
    return 0;
}