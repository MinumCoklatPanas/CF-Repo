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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1 ; i <= n ; i++) cin >> p[i];
    vector<int> q(n + 1);
    for (int i = 1 ; i <= n ; i++) q[p[i]] = i;
    for (int i = 1 ; i <= n ; i++)
        cout << q[i] << " ";
    cout << endl;
    return 0;
}