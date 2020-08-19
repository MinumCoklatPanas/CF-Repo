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

char tab[110][110];
bool taken[110][110];

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
        for (int j = 0 ; j < 26 ; j++)
        {
            int cnt = 0;
            for (int k = 1 ; k <= m ; k++)
            {
                cnt += (tab[i][k] == 'a' + j);
            }
            if (cnt > 1)
            {
                // cout << (char)(j + 'a') << endl;
                for (int k = 1 ; k <= m ; k++) if (tab[i][k] == 'a' + j)
                    taken[i][k] = 1;
            }
        }
    }

    for (int i = 1 ; i <= m ; i++)
    {
        for (int j = 0 ; j < 26 ; j++)
        {
            int cnt = 0;
            for (int k = 1 ; k <= n ; k++)
            {
                cnt += (tab[k][i] == 'a' + j);
            }
            if (cnt > 1)
            {
                // cout << (char)(j + 'a') << endl;
                for (int k = 1 ; k <= n ; k++) if (tab[k][i] == 'a' + j)
                    taken[k][i] = 1;
            }
        }
    }

    string ans;
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= m ; j++) if (!taken[i][j])
            ans += tab[i][j];
    cout << ans << endl;
    return 0;
}