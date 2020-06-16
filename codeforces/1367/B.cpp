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

int tab[55];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ganjil = 0;
        int genap = 0;
        for (int i = 0 ; i < n ; i++)
        {
            cin >> tab[i];
            if (tab[i] % 2 != i % 2)
            {
                if (tab[i] & 1)
                    ganjil++;
                else
                    genap++;
            }
        }
        if (ganjil != genap)
            cout << -1 << endl;
        else
            cout << ganjil << endl;
    }
    return 0;
}