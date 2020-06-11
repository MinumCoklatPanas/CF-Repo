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

ll solve(ll a,ll b)
{
    if (a % b == 0) return a / b;
    if (a == 1) return b;
    if (a > b)
    {
        ll single = (a / b);
        a = a - ((a / b) * b);
        return single + solve(a,b);
    }
    else
    {
        return (b / a) + solve(a,b % a);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a,b;
    cin >> a >> b;
    cout << solve(a,b) << endl;
    return 0;
}