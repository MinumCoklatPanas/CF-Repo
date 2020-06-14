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

int tab[200010];
bool bisa[1000010];
int ada[1000010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        ada[ta] += 1;
        tab[i] = ta;
    }
    memset(bisa,1,sizeof(bisa));
    for (int i = 1 ; i <= 1000000 ; i++) if (ada[i])
    {
        // cout << i << ": ";
        for (int j = i + i ; j <= 1000000 ; j += i)
        {
            // cout << j << " ";
            bisa[j] = 0;
        }
        
        bisa[i] &= (ada[i] == 1);
        // cout << bisa[i];
        // cout << endl;
    }
    // cout << bisa[24] << endl; 
    int ans = 0;
    for (int i = 1 ; i <= n ; i++)
        ans += bisa[tab[i]];
    cout << ans << endl;
    return 0;
}