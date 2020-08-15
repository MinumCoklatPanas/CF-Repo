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

map<char,bool> ada;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    string s;
    cin >> s;
    for (int i = 0 ; i < s.length() ; i++) if (isalpha(s[i]))
        ada[s[i]] = 1;
    int l = 0;
    int r = s.length() - 1;
    vector< pair<int,int> > kosong;
    while (l <= r)
    {
        // cout << l << " " << r << endl;
        if (s[l] != '?' && s[r] != '?')
        {
            if (s[l] != s[r])
            {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
        else
        {
            if (s[l] == '?')
            {
                if (s[r] == '?')
                {
                    kosong.emplace_back(l,r);
                }
                else
                    s[l] = s[r];
            }
            else
            if (s[r] == '?')
            {
                s[r] = s[l];
            }
        }
        ++l;
        --r;
    }
    reverse(kosong.begin(),kosong.end());
    for (auto it : kosong)
    {
        bool ok = 0;
        for (char i = 'a' + k - 1 ; i >= 'a' ; i--) if (!ada[i])
        {
            s[it.first] = i;
            s[it.second] = i;
            ok = 1;
            ada[i] = 1;
            break;
        }
        if (!ok)
        {
            s[it.first] = s[it.second] = 'a';
        }
    }
    for (char i = 'a' ; i <= 'a' + k - 1 ; i++) if (!ada[i])
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << s << endl;
    return 0;
}