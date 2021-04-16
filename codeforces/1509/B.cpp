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

void solve()
{
    int n;
    cin >> n;
    set<int> t;
    string s;
    cin >> s;
    vector<int> prefM(n,0);
    vector<int> prefT(n,0);
    for (int i = 0 ; i < n ; i++)
    {
        if (i != 0)
        {
            prefM[i] = prefM[i - 1];
            prefT[i] = prefT[i - 1];
        }
        prefM[i] += (s[i] == 'M');
        prefT[i] += (s[i] == 'T');
    }
    if (2 * prefM[n - 1] != prefT[n - 1])
    {
        cout << "NO\n";
        return;
    }
    for (int i = 0 ; i < n ; i++)
    {
        if (prefM[i] > prefT[i])
        {
            cout << "NO\n";
            return;
        }
    }
    int sumM = 0;
    int sumT = 0;
    for (int i = n - 1 ; i >= 0 ; i--)
    {
        sumM += (s[i] == 'M');
        sumT += (s[i] == 'T');
        if (sumM > sumT)
        {
            cout << "NO\n";
            return;
        }
    }
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