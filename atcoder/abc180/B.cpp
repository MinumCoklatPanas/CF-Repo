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
#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int M = 0;
    int E = 0;
    int C = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        M += abs(ta);
        E += ta * ta;
        C = max(C,abs(ta));
    }
    double EE = (double)sqrt(E);
    cout << M << endl;
    cout << setprecision(12) << fixed;
    cout << EE << endl;
    cout << C << endl;
    return 0;
}