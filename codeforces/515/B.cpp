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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<bool> boy(n),girl(m);
    int k;
    cin >> k;
    for (int i = 1 ; i <= k ; i++)
    {
        int ta;
        cin >> ta;
        boy[ta] = 1;
    }
    cin >> k;
    for (int i = 1 ; i <= k ; i++)
    {
        int ta;
        cin >> ta;
        girl[ta] = 1;
    }
    for (int i = 0 ; i < 100000 ; i++)
    {
        int a = i % n;
        int b = i % m;
        bool state = boy[a] | girl[b];
        boy[a] = state;
        girl[b] = state;
        // cout << a << " " << b << " " << boy[a] << " " << girl[b] << endl;
    }
    bool can = 1;
    for (int i = 0 ; i < n ; i++)
        can &= boy[i];
    for (int i = 0 ; i < m ; i++)
        can &= girl[i];
    if (can)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}