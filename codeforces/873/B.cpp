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

map<int,int> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    mp[0] = -1;
    int bal = 0;
    int ans = 0;
    for (int i = 0 ; i < n ; i++)
    {
        if (s[i] == '0') ++bal;
        if (s[i] == '1') --bal;
        if (mp.count(bal))
            ans = max(ans,i - mp[bal]);
        else
            mp[bal] = i;
    }
    cout << ans << endl;
    return 0;
}