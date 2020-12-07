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

bool can[100010];
vector<int> pos[2];

bool cek(int ix)
{
    for (auto it : pos[ix])
    {
        int nxt = upper_bound(pos[ix ^ 1].begin(), pos[ix ^ 1].end(),it + 1) - pos[ix ^ 1].begin();
        if (nxt != pos[ix ^ 1].size())
        { 
            // cout << ix << " " << it << endl;
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(can,1,sizeof(can));
    string s;
    cin >> s;
    for (int i = 0 ; i + 1 < s.length() ; i++)
    {
        if (s[i] == 'A' && s[i + 1] == 'B')
            pos[0].push_back(i);
        if (s[i] == 'B' && s[i + 1] == 'A')
            pos[1].push_back(i);
    }
    if (cek(0))
        cout << "YES\n";
    else
    if (cek(1))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}