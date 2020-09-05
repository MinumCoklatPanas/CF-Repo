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

int n,m;
int a[1010];
int b[1010];

bool cek(double x)
{
    double curWeight = m + x;
    double curFuel = x;
    for (int i = 1 ; i <= n ; i++)
    {
        double takeOffFuel = (curWeight / (double)a[i]);
        if (takeOffFuel - curFuel > -EPS) return false;
        curFuel -= takeOffFuel;
        curWeight -= takeOffFuel;
        double landingFuel = (curWeight / (double)b[i]);
        if (landingFuel - curFuel > -EPS) return false;
        curFuel -= landingFuel;
        curWeight -= landingFuel;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
        cin >> a[i];
    for (int i = 1 ; i <= n ; i++)
        cin >> b[i];
    a[n + 1] = a[1];
    b[n + 1] = b[1];
    double l = 0;
    double r = INF + 1;
    for (int i = 1 ; i <= 50000 ; i++)
    {
        double mid = (l + r) * 0.5;
        if (cek(mid))
            r = mid;
        else
            l = mid;
    }
    cout << setprecision(9) << fixed;
    if (l == INF + 1)
        cout << -1 << endl;
    else
        cout << l << endl;
    return 0;
}