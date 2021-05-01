#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    int mx = 0;
    int ix = -1;
    for (int i = 0 ; i < n ; i++)
    {
        int sum = 0;
        int last = tab[i];
        for (int j = i ; j >= 0 ; j--)
        {
            last = min(last,tab[j]);
            sum += last;
        }
        last = tab[i];
        for (int j = i + 1 ; j < n ; j++)
        {
            last = min(last,tab[j]);
            sum += last;
        }
        if (sum > mx)
        {
            mx = sum;
            ix = i;
        }
    }
    int last = tab[ix];
    for (int i = ix ; i >= 0 ; i--)
    {
        last = min(last,tab[i]);
        tab[i] = last;
    }
    last = tab[ix];
    for (int i = ix ; i < n ; i++)
    {
        last = min(last,tab[i]);
        tab[i] = last;
    }
    for (auto it : tab)
        cout << it << " ";
    cout << endl;
    return 0;
}