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

int tab[1010][1010];
int row[1010][1010];
int col[1010][1010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= m ; j++)
            cin >> tab[i][j];
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
            row[i][j] = row[i][j - 1] + tab[i][j];
        }
    }
    
    for (int i = 1 ; i <= m ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            col[j][i] = col[j - 1][i] + tab[j][i];
        }
    }
    // for (int i = 1 ; i <= n ; i++)
    // {
    //     for (int j = 1 ; j <= m ; j++)
    //         cout << row[i][j] << " ";
    //     cout << endl;
    // }
    // cout << row[1][4] << " " << row[1][1] << endl;
    int ans = 0;
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= m ; j++) if (!tab[i][j])
        {
            ans += (row[i][j - 1] > 0);
            ans += (row[i][m] - row[i][j] > 0);
            ans += (col[i - 1][j] > 0);
            ans += (col[n][j] - col[i][j] > 0);
            // cout << row[i][m] - row[i][j] << endl;
            // return 0;
        }
    cout << ans << endl;
    return 0;
}