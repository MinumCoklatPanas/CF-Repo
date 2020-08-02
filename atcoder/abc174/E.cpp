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
int n,k;

int cei(int x,int y)
{
    return ((x / y) + (x % y != 0));
}

bool cek(int x)
{
    int cnt = 0;
    for (int i = 1 ; i <= n ; i++)
        cnt += cei(tab[i],x) - 1;
    // cout << cnt << endl;
    return (cnt <= k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++)
        cin >> tab[i];
    // cout << cek(5) << endl;
    // return 0;
    int l = 1;
    int r = INF;
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        // cout << l << " " << r << " " << mid << endl;
        if (cek(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if (cek(l))
    {
        cout << l << endl;
    }
    else
        cout << r << endl;
    return 0;
}