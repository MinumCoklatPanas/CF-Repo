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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,k;
char tab[300010];
void solve()
{
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) cin >> tab[i];
    for (int i = 1 ; i <= k ; i++)
    {
        set<char> st;
        for (int j = i ; j <= n ; j += k) if (tab[j] != '?')
            st.insert(tab[j]);
        if (st.size() == 2)
        {
            cout << "NO\n";
            return;
        }
        if (!st.empty())
        {
            for (int j = i ; j <= n ; j += k) tab[j] = *st.begin();
        }
    }
    int cnt0 = 0;
    int cnt1 = 0;
    for (int i = 1 ; i <= k ; i++)
    {
        cnt0 += (tab[i] == '0');
        cnt1 += (tab[i] == '1');
    }
    if (cnt0 > k / 2 || cnt1 > k / 2)
        cout << "NO\n";
    else
        cout << "YES\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}