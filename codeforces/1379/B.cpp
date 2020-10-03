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

int cei(int x,int y)
{
    return (x / y) + (x % y != 0);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll l,r,m;
        cin >> l >> r >> m;
        for (int i = l ; i <= r ; i++)
        {
            int n = (m + r - l) / i;
            if (n == 0) continue;
            int na = n * i;
            if (abs(na - m) <= r - l)
            {
                int diff = abs(na - m);
                if (diff <= r - l)
                {
                    int b = r;
                    int c = r - diff;
                    if (na - m > 0)
                        swap(b,c);
                    cout << i << " " << b << " " << c << endl;
                    break;
                }
            }
        }
    }
    return 0;
}