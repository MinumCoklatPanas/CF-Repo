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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed << endl;
    int a,b;
    cin >> a >> b;
    if (a == b)
    {
        cout << (double)a << endl;
        return 0;
    }
    if (a < b)
    {
        cout << "-1\n";
        return 0;
    }
    double n = (double)(a + b) / (double) b - 1.0;
    n = floor(n);
    int tmp = (int)n;
    if (tmp % 2 == 0)
        n -= 1.0;
    double x = (double)(a + b) / (n + 1.0);
    double k = x - b;
    double tmp2 = n * x + k;
    double tmp3 = x - k;
    // cout << tmp2 << " " << tmp3 << endl;
    cout << x << endl;
    return 0;
}