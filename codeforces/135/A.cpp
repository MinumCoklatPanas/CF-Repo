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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    bool satu = 1;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
        if (tab[i] != 1)
        {
            satu = 0;
        }
    }
    if (satu)
    {
        for (int i = 1 ; i < n ; i++)
            cout << 1 << " ";
        cout << 2 << endl;
        return 0;
    }
    sort(tab + 1,tab + n + 1);
    cout << 1 << " ";
    for (int i = 1 ; i < n ; i++)
        cout << tab[i] << " ";
    cout << endl;
    return 0;
}