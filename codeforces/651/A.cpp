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
    int a,b;
    cin >> a >> b;
    int ans = 0;
    while (1)
    {
        if (a == 1 && b == 1) break;
        if (a < 1 || b < 1) break;
        if (a < b)
        {
            ++a;
            b -= 2;
        }
        else
        {
            ++b;
            a -= 2;
        }
        ++ans;
    }
    cout << ans << endl;
    return 0;
}