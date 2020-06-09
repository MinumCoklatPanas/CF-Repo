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

int tab[100010];
int num[2][100010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
        cin >> tab[i];
    int i = 1;
    int tmp = 1;
    memset(num,-1,sizeof(num));
    while (i + 1 <= n)
    {
        int cur = tab[i];
        num[0][i] = tmp;
        int tmp2 = i;
        while (i > 1 && tab[tmp2 - 1] == tab[tmp2])
        {
            num[0][tmp2 - 1] = tmp;
            --tmp2;
        }
        // cout << i << ": start " << tmp << " " << tab[i] << " " << tab[i + 1] << endl;
        while (i + 1 <= n && tab[i] <= tab[i + 1])
        {
            // cout << "yo\n";
            num[0][i + 1] = tmp;
            ++i;
        }
        ++tmp;
        tmp2 = i;
        // cout << i << ": i\n";
        while (i > 1 && tab[tmp2 - 1] == tab[tmp2])
        {
            num[1][tmp2 - 1] = tmp;
            --tmp2;
        }
        num[1][i] = tmp;
        // cout << i << endl;
        while (i + 1 <= n && tab[i] >= tab[i + 1])
        {
            num[1][i + 1] = tmp;
            ++i;
        }
        // num[1][i] = tmp;
        // ++i;
        ++tmp;
    }
    // for (int i = 1 ; i <= n ; i++)
    //     cout << num[0][i] << " ";
    // cout << endl;
    // for (int i = 1 ; i <= n ; i++)
    //     cout << num[1][i] << " ";
    // cout << endl;
    // for (int i = 1 ; i <= n ; i++)
    //     cout << num[i] * sign[num[i]] << " ";
    // cout << endl;
    while (m--)
    {
        int l,r;
        cin >> l >> r;
        if (r - l <= 1)
        {
            cout << "Yes\n";
            continue;
        }
        if ((num[0][l] == num[0][r] && num[0][l] != -1) || (num[1][l] == num[1][r] && num[1][l] != -1))
            cout << "Yes\n";
        else
        if (num[0][l] + 1 == num[1][r])
        {
            cout << "Yes\n";
        }
        else
            cout << "No\n";
        
    }
    return 0;
}