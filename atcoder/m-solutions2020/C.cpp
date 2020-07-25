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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++)
        cin >> tab[i];
    double cur = 0.0;
    for (int i = 1 ; i <= k ; i++)
        cur += log(tab[i]);
    for (int i = k + 1 ; i <= n ; i++)
    {
        double last = cur;
        cur -= log(tab[i - k]);
        cur += log(tab[i]);
        if (cur > last)
            cout << "Yes\n";
        else
            cout <<  "No\n";
    }
    return 0;
}