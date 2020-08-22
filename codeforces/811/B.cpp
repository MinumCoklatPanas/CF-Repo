#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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

int tab[10010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin >> n >> q;
    for (int i = 1 ; i <= n ; i++)
        cin >> tab[i];
    while (q--)
    {
        int l,r,x;
        cin >> l >> r >> x;
        if (x > r || x < l)
            cout << "Yes\n";
        else
        {
            int urutan = 0;
            for (int j = l ; j <= r ; j++) if (tab[j] <= tab[x])
            {
                ++urutan;
            }
            int cnt = x - l + 1;
            if (urutan == cnt)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}