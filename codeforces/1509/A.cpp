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
    vector<int> ganjil,genap;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        if (ta & 1)
            ganjil.push_back(ta);
        else
            genap.push_back(ta);
    }
    for (auto it : ganjil)
        cout << it << " ";
    for (auto it : genap)
        cout << it << " ";
    cout << endl;
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