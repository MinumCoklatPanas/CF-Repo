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
#define MULTI_TC 0

int getTC()
{
    if (MULTI_TC)
    {
        int t;
        cin >> t;
        return t;
    }
    else return 1;
}


void solve()
{
    string s;
    cin >> s;
    string t;
    cin >> t;
    vector<int> frek(26,0);
    queue<int> q;
    for (int i = 0 ; i < s.length() ; i++)
    {
        if ('a' <= s[i] && s[i] <= 'z')
            frek[s[i] - 'a']++;
        else
            q.push(i);
    }
    // cerr << q.size() << endl;
    vector<int> need(26,0);
    for (int i = 0 ; i < t.length() ; i++)
        need[t[i] - 'a']++;
    for (int i = 1 ; i <= s.length() && !q.empty() ; i++)
    {
        for (int j = 0 ; j < 26 && !q.empty() ; j++)
        {
            if (need[j] > frek[j])
            {
                for (int k = 0 ; k < need[j] - frek[j] && !q.empty() ; k++)
                {
                    s[q.front()] = 'a' + j;
                    q.pop();
                }
                frek[j] = 0;
            }
            else
                frek[j] -= need[j];
        }
    }
    cout << s << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = getTC();
    while (t--)
    {
        solve();
    }
    return 0;
}