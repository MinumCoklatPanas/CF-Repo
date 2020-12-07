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

vector<int> ab[30][30];
vector<int> a[30];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s,t;
    cin >> n >> s >> t;
    int dist = 0;
    for (int i = 0 ; i < n ; i++) if (s[i] != t[i])
    {
        ab[s[i] - 'a'][t[i] - 'a'].push_back(i + 1);
        a[s[i] - 'a'].push_back(i + 1);
        ++dist;
    }

    //dist - 2
    for (int i = 0 ; i < n ; i++) if (s[i] != t[i])
    {
        if (ab[t[i] - 'a'][s[i] - 'a'].size() > 0)
        {
            cout << dist - 2 << endl;
            cout << i + 1 << " " << ab[t[i] - 'a'][s[i] - 'a'][0] << endl;
            return 0;   
        }
    }

    //dist - 1
    for (int i = 0 ; i < n ; i++) if (s[i] != t[i])
    {
        if (a[t[i] - 'a'].size() > 0)
        {
            cout << dist - 1 << endl;
            cout << i + 1 << " " << a[t[i] - 'a'][0] << endl;
            return 0;
        }
    }
    cout << dist << endl;
    cout << "-1 -1\n";
    return 0;
}