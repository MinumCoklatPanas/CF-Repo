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

map<char,char> change;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s,t;
    cin >> s >> t;
    for (int i = 0 ; i < s.length() ; i++) if (s[i] != t[i])
    {
        if ((change.count(s[i]) && !change.count(t[i])) || (change.count(t[i]) && !change.count(s[i])))
        {
            cout << "-1\n";
            return 0;
        }
        if (!change.count(s[i]) && !change.count(t[i]))
        {
            change[s[i]] = t[i];
            change[t[i]] = s[i];
        }
        else
        if (change[s[i]] != t[i])
        {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0 ; i < s.length() ; i++) if (change.count(s[i]))
    {
        if (change[s[i]] != t[i])
        {
            cout << "-1\n";
            return 0;
        }
    }
    set< pair<char,char> > st;
    for (auto it : change)
    {
        st.insert({min(it.first,it.second),max(it.first,it.second)});
    }
    cout << st.size() << endl;
    for (auto it : st)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}