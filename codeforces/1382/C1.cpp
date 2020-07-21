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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t;
        cin >> t;
        int curIx = n - 1;
        vector<int> ans;
        while (s.length() > 0)
        {
            // cout << s << " " << t << endl;
            if (s == t) break;
            if (s[0] != t.back())
            {
                ans.push_back(s.length());
                reverse(s.begin(),s.end());
                s.pop_back();
                t.pop_back();
                for (int i = 0 ; i < s.length() ; i++)
                {
                    if (s[i] == '1')
                        s[i] = '0';
                    else
                        s[i] = '1';
                }
            }
            else
            {
                int simpan = -1;
                for (int i = 0 ; i < s.length() ; i++) if (s[0] == s[i])
                {
                    simpan = i;
                    break;
                }
                ans.push_back(simpan + 1);
                reverse(s.begin(),s.begin() + simpan + 1);
                for (int i = 0 ; i <= simpan ; i++)
                {
                    if (s[i] == '1')
                        s[i] = '0';
                    else
                        s[i] = '1';
                }
            }
        }
        cout << ans.size() << " ";
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}