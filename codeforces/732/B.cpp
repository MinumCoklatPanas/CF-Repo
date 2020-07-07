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

int tab[510];
int ans[510];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
        ans[i] = tab[i];
    }
    int ret = 0;
    for (int i = 2 ; i <= n ; i++)
    {
        if (ans[i] + ans[i - 1] < k)
        {
            int tmp = k - ans[i] - ans[i - 1];
            ret += tmp;
            ans[i] += tmp;
       }
    }
    cout << ret << endl;
    for (int i = 1 ; i <= n ; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}