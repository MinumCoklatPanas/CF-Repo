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
    int t;
    cin >> t;
    while (t--)
    {
        int n,x;
        cin >> n >> x;
        if (n <= 2)
        {
            cout << "1\n";
            continue;
        }
        int cur = 2;
        for (int i = 2 ; ; i++)
        {
            cur += x;
            if (cur >= n)
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
