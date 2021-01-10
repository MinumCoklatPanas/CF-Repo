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
    vector<int> a(n),b(n);
    for (auto &it : a) cin >> it;
    for (auto &it : b) cin >> it;
    int sum = 0;
    for (int i = 0 ; i < n ; i++)
        sum += a[i] * b[i];
    if (sum == 0)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}